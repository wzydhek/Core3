#include "SetExperienceCommand.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/player/PlayerManager.h"

SetExperienceCommand::SetExperienceCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SetExperienceCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	try {
		ManagedReference<SceneObject*> object = server->getZoneServer()->getObject(target);

		ManagedReference<CreatureObject*> player = nullptr;

		StringTokenizer args(arguments.toString());

		if (object == nullptr || !object->isPlayerCreature()) {
			String firstName;

			if (args.hasMoreTokens()) {
				args.getStringToken(firstName);
				player = server->getZoneServer()->getPlayerManager()->getPlayer(firstName);
			}

		} else {
			player = cast<CreatureObject*>(object.get());
		}

		if (player == nullptr) {
			creature->sendSystemMessage("invalid arguments for setExperience command. usage: setExperience <firstName> <experienceType> <amount>");
			return GENERALERROR;
		}

		String xpType;
		args.getStringToken(xpType);
		int amount = args.getIntToken();

		int num = (player->getSlottedObject("ghost").castTo<PlayerObject*>())->getExperience(xpType);
		amount -= num;
		player->getZoneServer()->getPlayerManager()->awardExperience(player, xpType, amount);

		creature->sendSystemMessage("Experience Successfully changed");

	} catch (Exception& e) {
		creature->sendSystemMessage("invalid arguments for setExperience command. usage: setExperience <firstName> <experienceType> <amount>");
	}

	return SUCCESS;
}