#include "ConversationTemplate.h"

#include "server/zone/managers/conversation/ConversationManager.h"

ConversationTemplate::ConversationTemplate(uint32 hashCode) : Logger("ConversationTemplate") {
	screens.setNoDuplicateInsertPlan();
	crc = hashCode;

	conversationTemplateType = ConversationTemplateTypeNormal;
}

ConversationTemplate::~ConversationTemplate() {
}

void ConversationTemplate::readObject(LuaObject* templateData) {
	initialScreenID = templateData->getStringField("initialScreen");

	String templateType;

	try {
		templateType = templateData->getStringField("templateType");
	}
	catch (Exception&) {
		Logger::info("Missing templateType.", true);
		templateType = "Normal";
	}

	if (templateType == "DeliverNPC") {
		conversationTemplateType = ConversationTemplateTypeDeliverMission;
	}
	else if (templateType == "InformantNPC") {
		conversationTemplateType = ConversationTemplateTypeInformantMission;
	}
	else if (templateType == "Lua") {
		conversationTemplateType = ConversationTemplateTypeLua;
	}
	else if (templateType == "Personality") {
		conversationTemplateType = ConversationTemplateTypePersonality;
	}
	else {
		conversationTemplateType = ConversationTemplateTypeNormal;
	}

	luaClassHandler = templateData->getStringField("luaClassHandler");

	LuaObject screensTable = templateData->getObjectField("screens");

	for (int i = 1; i <= screensTable.getTableSize(); ++i) {
		lua_rawgeti(templateData->getLuaState(), -1, i);

		LuaObject luaObj(templateData->getLuaState());

		Reference<ConversationScreen*> screen = new ConversationScreen();
		screen->readObject(&luaObj);

		screens.put(screen->getScreenID(), screen);

		luaObj.pop();
	}

	screensTable.pop();

	ConversationManager::instance()->getConversationObserver(crc);
}

const String& ConversationTemplate::getLuaClassHandler() const {
	return luaClassHandler;
}

ConversationScreen* ConversationTemplate::getInitialScreen() const {
	return screens.get(initialScreenID);
}

ConversationScreen* ConversationTemplate::getScreen(const String& screenID) const {
	return screens.get(screenID);
}

ConversationTemplate::ConversationTemplateType ConversationTemplate::getConversationTemplateType() const {
	return conversationTemplateType;
}

uint32 ConversationTemplate::getCRC() const {
	return crc;
}