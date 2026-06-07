/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "server/zone/objects/creature/conversation/DeliverMissionConversationObserver.h"

DeliverMissionConversationObserverImplementation::DeliverMissionConversationObserverImplementation(unsigned int convoTemplateCRC) :
	ConversationObserverImplementation(convoTemplateCRC) {
	//Register screen handler.
	registerScreenHandler(DeliverMissionScreenHandler::STARTSCREENHANDLERID, &deliverMissionScreenHandler);
}
