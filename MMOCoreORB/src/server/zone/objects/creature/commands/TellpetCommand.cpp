#include "TellpetCommand.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/creature/PetManager.h"

TellpetCommand::TellpetCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int TellpetCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<PlayerObject*> player = creature->getPlayerObject();
	if (player == nullptr)
		return GENERALERROR;

	// Send message to all player's pets within range
	for (int i = 0; i < player->getActivePetsSize(); ++i) {
		ManagedReference<AiAgent*> pet = player->getActivePet(i);
		if (pet != nullptr) {
			if (creature->isInRange(pet, 128.f)) {
				Locker clocker(pet, creature);
				server->getZoneServer()->getPetManager()->handleChat(creature, pet, arguments.toString());
			}
		}
	}

	return SUCCESS;
}