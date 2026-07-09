#include "DenyTradeMessage.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sessions/TradeSession.h"

DenyTradeMessage::DenyTradeMessage() : BaseMessage(6) {
	insertShort(1);
	insertInt(0x6EC28670);
}

DenyTradeMessageCallback::DenyTradeMessageCallback(ZoneClientSession *session, ZoneProcessServer *server) : MessageCallback(session, server) {
}

void DenyTradeMessageCallback::parse(Message *message) {
}

void DenyTradeMessageCallback::run() {
	ManagedReference<CreatureObject *> player = client->getPlayer();

	if (player == nullptr)
		return;

	Locker _locker(player);

	Reference<TradeSession *> tradeContainer = player->getActiveSession(SessionFacadeType::TRADE).castTo<TradeSession *>();

	if (tradeContainer == nullptr) {
		player->error() << player->getDisplayedName() << " ID: " << player->getObjectID() << " - DenyTradeMessage without TradeSession.";
		return;
	}

	uint64 targetID = tradeContainer->getTradeTargetPlayer();

	Reference<ZoneServer *> zoneServer = player->getZoneServer();

	if (zoneServer == nullptr)
		return;

	ManagedReference<CreatureObject *> target = zoneServer->getObject(targetID).castTo<CreatureObject *>();

	if (target != nullptr)
		target->sendMessage(new DenyTradeMessage());
}