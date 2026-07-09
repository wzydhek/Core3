#include "DroidPersonalityModuleTemplate.h"

DroidPersonalityModuleTemplate::DroidPersonalityModuleTemplate() {
}

DroidPersonalityModuleTemplate::~DroidPersonalityModuleTemplate() {
}

void DroidPersonalityModuleTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);
	reactionName = templateData->getStringField("reactionName");
	attrName = templateData->getStringField("attrName");
	convTemplate = templateData->getStringField("conversationTemplate");
	personalityStf = templateData->getStringField("personalityStf");
}

String& DroidPersonalityModuleTemplate::getReactionName() {
	return reactionName;
}

String& DroidPersonalityModuleTemplate::getChipName() {
	return attrName;
}

String& DroidPersonalityModuleTemplate::getConversationTemplate() {
	return convTemplate;
}

String& DroidPersonalityModuleTemplate::getPersonalityStf() {
	return personalityStf;
}

bool DroidPersonalityModuleTemplate::isDroidPersonalityModuleTemplate() {
	return true;
}