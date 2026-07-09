#include "MissionAbortCallback.h"
#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/mission/MissionManager.h"
#include "server/zone/objects/mission/MissionObject.h"

MissionAbortCallback::MissionAbortCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), missionObjectID(0), objectControllerMain(objectControllerCallback) {
}

void MissionAbortCallback::parse(Message* message) {
	// System::out << message->toStringData() << endl;
	message->parseInt();
	missionObjectID = message->parseLong();
}

void MissionAbortCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr) {
		return;
	}

	auto zoneServer = player->getZoneServer();

	if (zoneServer == nullptr) {
		return;
	}

	ManagedReference<SceneObject*> mission = zoneServer->getObject(missionObjectID);

	if (mission == nullptr || !mission->isMissionObject()) {
		return;
	}

	MissionObject* missionObject = cast<MissionObject*>(mission.get());

	if (missionObject == nullptr) {
		return;
	}

	MissionManager* missionMan = zoneServer->getMissionManager();

	if (missionMan == nullptr) {
		return;
	}

	Locker lock(player);
	Locker clock(missionObject, player);

	missionMan->handleMissionAbort(missionObject, player, true);

	// MissionAbortResponse
	ObjectControllerMessage* abortResponse = new ObjectControllerMessage(player->getObjectID(), 0x0B, 0x142);

	if (abortResponse != nullptr) {
		abortResponse->insertLong(missionObject->getObjectID());
		player->sendMessage(abortResponse);
	}
}