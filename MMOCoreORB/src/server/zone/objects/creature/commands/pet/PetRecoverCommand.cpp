#include "PetRecoverCommand.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/managers/creature/PetManager.h"
#include "templates/params/creature/CreatureAttribute.h"
#include "server/zone/objects/creature/ai/AiAgent.h"

PetRecoverCommand::PetRecoverCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int PetRecoverCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	ManagedReference<PetControlDevice*> controlDevice = creature->getControlDevice().get().castTo<PetControlDevice*>();
	if (controlDevice == nullptr)
		return GENERALERROR;

	if (!creature->isAiAgent())
		return GENERALERROR;

	ManagedReference<AiAgent*> pet = cast<AiAgent*>(creature);
	if (pet == nullptr)
		return GENERALERROR;

	ManagedReference<CreatureObject*> player = pet->getLinkedCreature().get();

	if (player == nullptr)
		return GENERALERROR;

	Locker crossLocker(player, pet);
	Locker devLocker(controlDevice, pet);

	controlDevice->setLastCommand(PetManager::FOLLOW);

	// Check pet states
	if (!pet->isIncapacitated())
		return GENERALERROR;

	if (pet->getHAM(CreatureAttribute::HEALTH) <= 0)
		pet->healDamage(player, CreatureAttribute::HEALTH, 1 - pet->getHAM(CreatureAttribute::HEALTH));

	if (pet->getHAM(CreatureAttribute::ACTION) <= 0)
		pet->healDamage(player, CreatureAttribute::ACTION, 1 - pet->getHAM(CreatureAttribute::ACTION));

	if (pet->getHAM(CreatureAttribute::MIND) <= 0)
		pet->healDamage(player, CreatureAttribute::MIND, 1 - pet->getHAM(CreatureAttribute::MIND));

	pet->setFollowObject(player);
	pet->storeFollowObject();
	pet->setMovementState(AiAgent::FOLLOWING);

	// Player animation
	player->doAnimation("heal_other");

	return SUCCESS;
}