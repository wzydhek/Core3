#include "GroupMemberSpaceInviteResponseCallback.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/packets/object/GroupMemberSpaceInviteResponseMessage.h"

GroupMemberSpaceInviteResponseCallback::GroupMemberSpaceInviteResponseCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), objectControllerMain(objectControllerCallback), pilotID(0), decision(false) {
}

void GroupMemberSpaceInviteResponseCallback::parse(Message* message) {
	message->shiftOffset(4);
	pilotID = message->parseLong();
	decision = message->parseByte();
}

void GroupMemberSpaceInviteResponseCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	auto zoneServer = player->getZoneServer();

	if (zoneServer == nullptr)
		return;

	ManagedReference<SceneObject*> pilotScno = zoneServer->getObject(pilotID);

	if (pilotScno == nullptr)
		return;

	// Check again if the player is still within range and the same cell as the pilot
	if ((player->getParentID() != pilotScno->getParentID()) || !pilotScno->isInRange(player, 7.f))
		return;

	auto pilot = pilotScno.castTo<CreatureObject*>();

	if (pilot == nullptr)
		return;

	GroupMemberSpaceInviteResponseMessage* responseMsg = new GroupMemberSpaceInviteResponseMessage(player, pilot, decision);
	pilot->sendMessage(responseMsg);
}