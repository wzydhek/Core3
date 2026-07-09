#include "DeclineCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/chat/StringIdChatParameter.h"

DeclineCommand::DeclineCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int DeclineCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	uint64 inviterID = creature->getGroupInviterID();
	ManagedReference<SceneObject*> object = server->getZoneServer()->getObject(inviterID);

	if (object == nullptr || !object->isPlayerCreature())
		return GENERALERROR;

	CreatureObject* inviter = cast<CreatureObject*>(object.get());

	creature->updateGroupInviterID(0);

	StringIdChatParameter stringId;
	stringId.setStringId("group", "decline_leader");

	stringId.setTT(creature->getDisplayedName());

	inviter->sendSystemMessage(stringId);
	creature->sendSystemMessage("@group:decline_self");

	return SUCCESS;
}