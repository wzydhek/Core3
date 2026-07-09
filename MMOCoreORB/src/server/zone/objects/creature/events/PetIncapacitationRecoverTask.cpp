#include "PetIncapacitationRecoverTask.h"
#include "server/zone/managers/creature/PetManager.h"

PetIncapacitationRecoverTask::PetIncapacitationRecoverTask(AiAgent* pl, bool store) : Task() {
	pet = pl;
	autostore = store;
}

PetIncapacitationRecoverTask::~PetIncapacitationRecoverTask() {
}

void PetIncapacitationRecoverTask::run() {
	try {
		Locker petLocker(pet);

		pet->removePendingTask("incapacitationRecovery");

		if (!pet->isIncapacitated())
			return;

		int health = pet->getHAM(CreatureAttribute::HEALTH);

		if (health < 0)
			pet->setHAM(CreatureAttribute::HEALTH, 1);

		int action = pet->getHAM(CreatureAttribute::ACTION);

		if (action < 0)
			pet->setHAM(CreatureAttribute::ACTION, 1);

		int mind = pet->getHAM(CreatureAttribute::MIND);

		if (mind < 0)
			pet->setHAM(CreatureAttribute::MIND, 1);

		pet->setPosture(CreaturePosture::UPRIGHT);

		PetControlDevice* device = pet->getControlDevice().get().castTo<PetControlDevice*>();

		if (device == nullptr)
			return;

		pet->setAITemplate();

		Locker locker(device, pet);

		device->setLastCommand(PetManager::FOLLOW);

		ManagedReference<SceneObject*> lastCommander = device->getLastCommander();

		if (lastCommander != nullptr) {
			Locker clocker(lastCommander, pet);

			device->setLastCommandTarget(lastCommander);

			pet->setFollowObject(lastCommander);
			pet->storeFollowObject();

			pet->setMovementState(AiAgent::FOLLOWING);
		}

		if (autostore) {
			CreatureObject* owner = pet->getLinkedCreature().get();

			if (owner != nullptr) {
				PetControlDeviceStoreTask* storeTask = new PetControlDeviceStoreTask(device, owner, true);

				if (storeTask != nullptr)
					storeTask->execute();
			}
		}

	} catch (Exception& e) {
	}
}