/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "server/chat/StringIdChatParameter.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/packets/object/NpcConversationMessage.h"
#include "server/zone/packets/object/StopNpcConversation.h"
#include "server/zone/packets/object/StringList.h"
#include "server/zone/objects/player/sessions/ConversationSession.h"
#include "server/zone/managers/ship/tasks/SpaceCommTimerTask.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace conversation {

class ConversationOption : public Object {
	StringIdChatParameter optionText;
	UnicodeString customOption;
	String linkedScreenID;

public:
	ConversationOption(const StringIdChatParameter& opttext, const String& screenid);

	ConversationOption(const UnicodeString& customopt, const String& screenid);

	String& getLinkedScreenID();

	StringIdChatParameter& getOptionText();

	UnicodeString& getCustomOption();

	String getDisplayedName();

	bool isLinked();

	void setOptionText(const StringIdChatParameter& optionText);
};

class ConversationScreen : public Object {
	String screenID;

	//TODO: Consider multiple dialog texts that can be displayed for screens
	StringIdChatParameter dialogText;

	UnicodeString customText;

	String animation;
	String playerAnimation;

	Vector<Reference<ConversationOption*> > options;

	bool stopConversation, readOnly;

public:
	ConversationScreen();

	ConversationScreen(StringIdChatParameter dialogue, bool stopConv);

	/**
	 * Copy constructor.
	 */
	ConversationScreen(const ConversationScreen& objectToCopy);

	ConversationScreen* cloneScreen();

	/**
	 * Adds an option to this conversation screen.
	 * @param optionText The text to be displayed for the option.
	 * @param linkedScreenID The ID of the screen this option is linked.
	 */
	void addOption(const String& optionText, const String& linkedScreenID);

	void removeOption(int idx);

	void removeAllOptions();

	ConversationOption* getOption(int idx);

	String getOptionText(int idx) const;

	String getOptionLink(int idx) const;

	int getOptionCount();

	/**
	 * Sends this ConversationScreen to the creature passed in.
	 * @param player The player receiving the message.
	 * @param npc The npc the player is talking to.
	 */
	void sendTo(CreatureObject* player, SceneObject* npc);

	String& getScreenID();

	void readObject(LuaObject* luaObject);

	template<class T>
	inline void setDialogTextTT(const T& obj) {
		if (readOnly)
			throw Exception("Can't modify read only Conversation Screen!");

		dialogText.setTT(obj);
	}

	void setDialogTextTT(const String& file, const String& id);

	template<class T>
	inline void setDialogTextTO(const T& obj) {
		if (readOnly)
			throw Exception("Can't modify read only Conversation Screen!");

		dialogText.setTO(obj);
	}

	void setDialogTextTO(const String& file, const String& id);

	template<class T>
	inline void setDialogTextTU(const T& obj) {
		if (readOnly)
			throw Exception("Can't modify read only Conversation Screen!");

		dialogText.setTO(obj);
	}

	void setDialogTextTU(const String& file, const String& id);

	void setDialogTextDI(uint32 val);

	void setDialogTextDF(float val);

	void setDialogText(const String& fullPath);

	void setCustomDialogText(const UnicodeString& custom);

	void setDialogText(const StringIdChatParameter& param);

	void setStopConversation(bool stopConversation);

	StringIdChatParameter* getDialogText();
};

}
}
}
}
}

using namespace server::zone::objects::creature::conversation;
