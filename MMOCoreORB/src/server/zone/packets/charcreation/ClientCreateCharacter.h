/*
*			Copyright <SWGEmu>
*	See file COPYING for copying conditions.
*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ClientCreateCharacter : public BaseMessage {
public:
	// Full constructor matching Core3 server parsing
	ClientCreateCharacter(const UnicodeString& characterName, const String& templateName, float scaleFactor, const String& customAppearanceData, const String& hairTemplateName, const String& hairAppearanceData, const String& profession, const UnicodeString& biography, bool useNewbieTutorial);

	// Simple constructor for backward compatibility
	ClientCreateCharacter(const UnicodeString& name);
};
