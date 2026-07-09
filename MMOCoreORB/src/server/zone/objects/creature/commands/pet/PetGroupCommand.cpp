#include "PetGroupCommand.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/managers/creature/PetManager.h"
#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

PetGroupCommand::PetGroupCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int PetGroupCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!creature->isPet()) {
		return GENERALERROR;
	}

	ManagedReference<PetControlDevice*> controlDevice = creature->getControlDevice().get().castTo<PetControlDevice*>();

	if (controlDevice == nullptr)
		return GENERALERROR;

	ManagedReference<AiAgent*> pet = creature->asAiAgent();

	if (pet == nullptr) {
		return GENERALERROR;
	}

	ManagedReference<CreatureObject*> player = pet->getLinkedCreature().get();

	if (player == nullptr || !player->isPlayerCreature()) {
		return GENERALERROR;
	}

	// Check if droid has power
	if (controlDevice->getPetType() == PetManager::DROIDPET) {
		ManagedReference<DroidObject*> droidPet = cast<DroidObject*>(pet.get());

		if (droidPet == nullptr)
			return GENERALERROR;

		if (!droidPet->hasPower()) {
			creature->showFlyText("npc_reaction/flytext", "low_power", 204, 0, 0); // "*Low Power*"
			return GENERALERROR;
		}
	}

	ManagedReference<GroupObject*> group = pet->getGroup();

	if (group == nullptr) {
		Locker clocker(player, pet);

		GroupManager::instance()->inviteToGroup(player, pet);
	} else {
		GroupManager::instance()->leaveGroup(group, pet);
	}

	return SUCCESS;
}