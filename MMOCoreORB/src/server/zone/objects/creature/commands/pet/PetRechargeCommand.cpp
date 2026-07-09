#include "PetRechargeCommand.h"
#include "server/zone/managers/creature/PetManager.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/objects/creature/ai/DroidObject.h"

PetRechargeCommand::PetRechargeCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int PetRechargeCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	ManagedReference<PetControlDevice*> controlDevice = creature->getControlDevice().get().castTo<PetControlDevice*>();

	if (controlDevice == nullptr)
		return GENERALERROR;

	// Droid specific command
	if (controlDevice->getPetType() != PetManager::DROIDPET)
		return GENERALERROR;

	ManagedReference<DroidObject*> droidPet = cast<DroidObject*>(creature);

	if (droidPet == nullptr || droidPet->isDead() || droidPet->isIncapacitated())
		return GENERALERROR;

	ManagedReference<CreatureObject*> player = droidPet->getLinkedCreature().get();

	if (player == nullptr)
		return GENERALERROR;

	// Recharge
	Locker plocker(player, creature);
	droidPet->rechargeFromBattery(player);

	return SUCCESS;
}