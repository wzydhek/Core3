#include "CommandQueueRemove.h"

CommandQueueRemove::CommandQueueRemove(CreatureObject* creo, uint32 actioncnt, float timer, uint32 tab1, uint32 tab2) : ObjectControllerMessage(creo->getObjectID(), 0x1B, 0x117) {
	insertInt(actioncnt);
	insertFloat(timer);
	insertInt(tab1);
	insertInt(tab2);
}

CommandQueueRemoveCallback::CommandQueueRemoveCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), size(0), actionCount(0), actionCRC(0), objectControllerMain(objectControllerCallback) {
}

void CommandQueueRemoveCallback::parse(Message* message) {
	size = message->parseInt(); //?

	actionCount = message->parseInt();
	actionCRC = message->parseInt();
}

void CommandQueueRemoveCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	// ObjectController* objectController = server->getZoneServer()->getObjectController();
	player->deleteQueueAction(actionCount);
}