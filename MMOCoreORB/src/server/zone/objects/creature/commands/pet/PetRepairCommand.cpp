#include "PetRepairCommand.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/creature/PetManager.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

PetRepairCommand::PetRepairCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int PetRepairCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	ManagedReference<PetControlDevice*> controlDevice = creature->getControlDevice().get().castTo<PetControlDevice*>();

	if (controlDevice == nullptr)
		return GENERALERROR;

	// Droid specific command
	if (controlDevice->getPetType() != PetManager::DROIDPET)
		return GENERALERROR;

	ManagedReference<DroidObject*> droidPet = cast<DroidObject*>(creature);
	if (droidPet == nullptr)
		return GENERALERROR;

	// Target must be a droid
	Reference<DroidObject*> targetDroid = server->getZoneServer()->getObject(target, true).castTo<DroidObject*>();
	if (targetDroid == nullptr || !targetDroid->isDroidObject()) {
		droidPet->showFlyText("npc_reaction/flytext", "confused", 204, 0, 0); // "?!!?!?!"
		return GENERALERROR;
	}

	// Check range between droids
	if (!checkDistance(droidPet, targetDroid, 30.0f)) {						  // Same range as auto-repair
		droidPet->showFlyText("npc_reaction/flytext", "confused", 204, 0, 0); // "?!!?!?!"
		return GENERALERROR;
	}

	// Check if droid has power
	if (!droidPet->hasPower()) {
		droidPet->showFlyText("npc_reaction/flytext", "low_power", 204, 0, 0); // "*Low Power*"
		return GENERALERROR;
	}

	// Heal all target droid's wounds
	Locker clocker(targetDroid, droidPet);
	bool targetHealed = false;
	for (int attr = 0; attr <= 8; attr++) {
		if (targetDroid->getWounds(attr) > 0) {
			targetDroid->healWound(droidPet, attr, targetDroid->getWounds(attr), true, false);
			targetHealed = true;
		}
	}

	if (targetHealed) {
		droidPet->usePower(10);
		droidPet->doAnimation("heal_other");
		targetDroid->showFlyText("npc_reaction/flytext", "repaired", 0, 153, 0); // "*Repaired*"
		targetDroid->playEffect("clienteffect/healing_healdamage.cef", "");
	}

	return SUCCESS;
}