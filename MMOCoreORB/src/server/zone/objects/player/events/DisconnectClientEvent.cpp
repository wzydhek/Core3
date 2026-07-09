#include "DisconnectClientEvent.h"
#include "server/zone/ZoneClientSession.h"

DisconnectClientEvent::DisconnectClientEvent(CreatureObject* pl, ZoneClientSession* cl, int type) : Task() {
	player = pl;
	client = cl;
	eventType = type;
}

void DisconnectClientEvent::run() {
	if (player == nullptr || client == nullptr)
		return;

	Locker _locker(player);

	PlayerObject* ghost = player->getPlayerObject();

	if (ghost == nullptr)
		return;

#ifdef WITH_SWGREALMS_API
	String eventTypeStr;

	switch (eventType) {
		case DISCONNECT:
			eventTypeStr = "disconnect";
			break;
		case LOGOUT:
			eventTypeStr = "logout";
			break;
		case SETLINKDEAD:
			eventTypeStr = "setlinkdead";
			break;
		default:
			eventTypeStr = "unknown_" + String::valueOf(eventType);
			break;
	}

	SWGRealmsAPI::instance()->notifyDisconnectClient(client->getIPAddress(), ghost->getAccountID(), player->getObjectID(), eventTypeStr);
#endif // WITH_SWGREALMS_API

	ghost->setLastLogoutWorldPosition();

	switch (eventType) {
		case DISCONNECT:
			ghost->disconnect(false, true);
			break;
		case LOGOUT:
			ghost->logout(true);
			break;
		case SETLINKDEAD:
			ghost->setLinkDead();
			break;
	}
}