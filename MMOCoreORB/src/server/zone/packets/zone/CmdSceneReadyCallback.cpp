#include "CmdSceneReadyCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "CmdSceneReady.h"

CmdSceneReadyCallback::CmdSceneReadyCallback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server) {
}

void CmdSceneReadyCallback::parse(Message* message) {
}

void CmdSceneReadyCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr) {
		return;
	}

	Locker _locker(player);

	auto ghost = player->getPlayerObject();

	if (ghost != nullptr) {
		ghost->notifySceneReady();
	}
}