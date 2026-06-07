/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "server/zone/objects/creature/conversation/InformantMissionConversationObserver.h"

InformantMissionConversationObserverImplementation::InformantMissionConversationObserverImplementation(unsigned int convoTemplateCRC) :
	ConversationObserverImplementation(convoTemplateCRC) {
	//Register screen handler.
	registerScreenHandler(InformantMissionScreenHandler::STARTSCREENHANDLERID, &informantMissionScreenHandler);
}
