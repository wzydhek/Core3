/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "engine/engine.h"
#include "ConversationScreen.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace conversation {

class ConversationTemplate : public Object, public Logger {
public:
	enum ConversationTemplateType {
		ConversationTemplateTypeNormal,
		ConversationTemplateTypeDeliverMission,
		ConversationTemplateTypeInformantMission,
		ConversationTemplateTypeLua,
		ConversationTemplateTypePersonality
	};
protected:
	String initialScreenID;
	VectorMap<String, Reference<ConversationScreen*> > screens;
	ConversationTemplateType conversationTemplateType;
	uint32 crc;
	String luaClassHandler;

public:

	ConversationTemplate(uint32 hashCode);

	virtual ~ConversationTemplate();

	void readObject(LuaObject* templateData);

	const String& getLuaClassHandler() const;

	ConversationScreen* getInitialScreen() const;

	ConversationScreen* getScreen(const String& screenID) const;

	ConversationTemplateType getConversationTemplateType() const;

	uint32 getCRC() const;
};

}
}
}
}
}

using namespace server::zone::objects::creature::conversation;
