#include "MissionListRequestCallback.h"
#include "server/zone/managers/mission/MissionManager.h"
#include "server/zone/objects/tangible/terminal/mission/MissionTerminal.h"

MissionListRequestCallback::MissionListRequestCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), flags(0), seq(0), terminalObjectID(0), objectControllerMain(objectControllerCallback) {
}

void MissionListRequestCallback::parse(Message* message) {
	message->parseInt();
	flags = message->parseByte();
	seq = message->parseByte();

	terminalObjectID = message->parseLong();
}

void MissionListRequestCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	ManagedReference<SceneObject*> terminal = server->getZoneServer()->getObject(terminalObjectID);

	if (terminal == nullptr) {
		player->sendSystemMessage("@skill_teacher:skill_terminal_disabled");
		return;
	}

	if (!terminal->isMissionTerminal())
		return;

	MissionTerminal* missionTerminal = cast<MissionTerminal*>(terminal.get());

	StringBuffer taskName;

	taskName << "MissionListRequestCallback for MissionTerminal(" << missionTerminal->getObjectID() << ")"
			 << "; player=" << player->getObjectID() << "; flags=" << flags << "; seq=" << seq;

	setTaskName(taskName.toString());

	MissionManager* manager = server->getZoneServer()->getMissionManager();
	manager->handleMissionListRequest(missionTerminal, player, seq);
}