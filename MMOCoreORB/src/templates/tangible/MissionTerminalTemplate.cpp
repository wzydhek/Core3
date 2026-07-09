#include "MissionTerminalTemplate.h"

MissionTerminalTemplate::MissionTerminalTemplate() {
}

MissionTerminalTemplate::~MissionTerminalTemplate() {
}

void MissionTerminalTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	missionTerminalType = templateData->getStringField("missionTerminalType");
}

String& MissionTerminalTemplate::getMissionTerminalType() {
	return missionTerminalType;
}

bool MissionTerminalTemplate::isMissionTerminalTemplate() {
	return true;
}