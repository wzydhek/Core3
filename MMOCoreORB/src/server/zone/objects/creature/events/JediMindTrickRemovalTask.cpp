#include "JediMindTrickRemovalTask.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

JediMindTrickRemovalTask::JediMindTrickRemovalTask(CreatureObject* pet, CreatureObject* owner) : Task() {
	this->pet = pet;
	this->owner = owner;
}

void JediMindTrickRemovalTask::run() {
	CreatureObject* petCreo = pet.get();
	CreatureObject* petOwner = owner.get();

	if (petCreo == nullptr || petOwner == nullptr)
		return;

	AiAgent* petAgent = petCreo->asAiAgent();

	if (petAgent == nullptr)
		return;

	Locker locker(petAgent);

	ManagedReference<PetControlDevice*> controlDevice = petAgent->getControlDevice().get().castTo<PetControlDevice*>();

	if (controlDevice != nullptr && controlDevice->getPetType() == PetManager::FACTIONPET) {
		petAgent->addObjectFlag(ObjectFlag::FACTION_PET);
	} else {
		petAgent->addObjectFlag(ObjectFlag::PET);
	}

	petAgent->setMindTricked(false);
	petAgent->setCreatureLink(petOwner);

	uint32 ownerPvpStatusBitmask = petOwner->getPvpStatusBitmask();

	if (ownerPvpStatusBitmask & ObjectFlag::PLAYER)
		ownerPvpStatusBitmask &= ~ObjectFlag::PLAYER;

	petAgent->setPvpStatusBitmask(ownerPvpStatusBitmask);

	if (petAgent->isDead()) {
		Reference<StorePetTask*> task = new StorePetTask(petOwner, petAgent);
		task->execute();
	} else {
		petAgent->setFollowObject(petOwner);
		petAgent->storeFollowObject();

		petAgent->setHomeLocation(petOwner->getPositionX(), petOwner->getPositionZ(), petOwner->getPositionY(), petOwner->getParent().get().castTo<CellObject*>());
		petAgent->setNextStepPosition(petOwner->getPositionX(), petOwner->getPositionZ(), petOwner->getPositionY(), petOwner->getParent().get().castTo<CellObject*>());
		petAgent->clearPatrolPoints();

		petAgent->setMovementState(AiAgent::FOLLOWING);
	}

	petAgent->setAITemplate();
}