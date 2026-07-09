#include "PetStoreCommand.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/objects/intangible/tasks/PetControlDeviceStoreTask.h"

PetStoreCommand::PetStoreCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int PetStoreCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	ManagedReference<PetControlDevice*> controlDevice = creature->getControlDevice().get().castTo<PetControlDevice*>();

	if (controlDevice == nullptr)
		return GENERALERROR;

	ManagedReference<AiAgent*> pet = cast<AiAgent*>(creature);

	if (pet == nullptr)
		return GENERALERROR;

	ManagedReference<CreatureObject*> player = pet->getLinkedCreature().get();

	if (player == nullptr || !player->isPlayerCreature()) {
		return GENERALERROR;
	}

	PetControlDeviceStoreTask* storeTask = new PetControlDeviceStoreTask(controlDevice, player, false);

	if (storeTask != nullptr)
		storeTask->execute();

	return SUCCESS;
}