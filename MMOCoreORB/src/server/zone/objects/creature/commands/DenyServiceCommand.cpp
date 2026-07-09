#include "DenyServiceCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/player/sessions/EntertainingSession.h"

DenyServiceCommand::DenyServiceCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int DenyServiceCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<CreatureObject*> targetObject = server->getZoneServer()->getObject(target).castTo<CreatureObject*>();

	if (targetObject == nullptr)
		return GENERALERROR;

	if (targetObject == creature || !targetObject->isPlayerCreature())
		return GENERALERROR;

	ManagedReference<EntertainingSession*> session = creature->getActiveSession(SessionFacadeType::ENTERTAINING).castTo<EntertainingSession*>();

	if (session == nullptr)
		return GENERALERROR;

	StringIdChatParameter selfMessage;
	StringIdChatParameter otherMessage;

	if (session->isInDenyServiceList(targetObject)) {
		session->removeFromDenyServiceList(targetObject);

		selfMessage.setStringId("performance", "deny_service_remove_self");
		selfMessage.setTT(targetObject->getDisplayedName());

		otherMessage.setStringId("performance", "deny_service_remove_other");
		otherMessage.setTU(creature->getDisplayedName());

		creature->sendSystemMessage(selfMessage);
		targetObject->sendSystemMessage(otherMessage);
	} else {
		session->addToDenyServiceList(targetObject);

		selfMessage.setStringId("performance", "deny_service_add_self");
		selfMessage.setTT(targetObject->getDisplayedName());

		otherMessage.setStringId("performance", "deny_service_add_other");
		otherMessage.setTU(creature->getDisplayedName());

		creature->sendSystemMessage(selfMessage);
		targetObject->sendSystemMessage(otherMessage);
	}

	return SUCCESS;
}