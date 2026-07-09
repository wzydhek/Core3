#include "ChatDeleteAllPersistentMessagesCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"

ChatDeleteAllPersistentMessagesCallback::ChatDeleteAllPersistentMessagesCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), playerID(0), targetID(0) {
}

void ChatDeleteAllPersistentMessagesCallback::parse(Message* message) {
	playerID = message->parseLong();
	targetID = message->parseLong();
}

void ChatDeleteAllPersistentMessagesCallback::run() {
	ManagedReference<SceneObject*> obj = server->getZoneServer()->getObject(targetID);

	if (obj == nullptr || !obj->isPlayerCreature())
		return;

	CreatureObject* creature = cast<CreatureObject*>(obj.get());
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (creature == nullptr || player == nullptr)
		return;

	if (creature != player) {
		info("Player " + player->getDisplayedName() + " attempted to erase all persistent messages for player " + creature->getDisplayedName());
		StringIdChatParameter emptyFail("ui_pm", "delete_all_mail_fail"); // Unable to empty the mailbox of %TT.
		emptyFail.setTT(creature->getDisplayedName());
		player->sendSystemMessage(emptyFail);
		return;
	}

	PlayerObject* ghost = player->getPlayerObject();
	StringIdChatParameter emptyPass("ui_pm", "delete_all_mail_success"); //	You have successfully emptied the mailbox of %TT.
	emptyPass.setTT(player->getDisplayedName());

	if (ghost == nullptr)
		return;

	Locker locker(player);

	ghost->deleteAllPersistentMessages();
	player->sendSystemMessage(emptyPass);
}