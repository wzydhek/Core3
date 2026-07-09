#include "WipeItemsCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/chat/ChatManager.h"
#include "server/zone/objects/scene/SceneObject.h"

WipeItemsCommand::WipeItemsCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int WipeItemsCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
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
				player = server->getZoneServer()->getChatManager()->getPlayer(firstName);
			}

		} else {
			player = cast<CreatureObject*>(object.get());
		}

		if (player == nullptr) {
			creature->sendSystemMessage("Invalid arguments for /wipeItems. Usage: /wipeItems playerName");
			return GENERALERROR;
		}

		Locker clocker(player, creature);

		SceneObject* inventory = player->getSlottedObject("inventory");

		if (inventory == nullptr)
			return GENERALERROR;

		while (inventory->getContainerObjectsSize() > 0) {
			ManagedReference<SceneObject*> object = inventory->getContainerObject(0);
			Locker sceneObjectLocker(object);
			object->destroyObjectFromWorld(true);
			object->destroyObjectFromDatabase(true);
		}

		creature->sendSystemMessage(player->getFirstName() + "'s inventory has been wiped.");

	} catch (Exception& e) {
		creature->sendSystemMessage("Invalid arguments for /wipeItems. Usage: /wipeItems playerName");
	}

	return SUCCESS;
}