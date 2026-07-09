#include "ConversationScreen.h"

ConversationOption::ConversationOption(const StringIdChatParameter& opttext, const String& screenid) {
	optionText = opttext;
	linkedScreenID = screenid;
}

ConversationOption::ConversationOption(const UnicodeString& customopt, const String& screenid) {
	customOption = customopt;
	linkedScreenID = screenid;
}

String& ConversationOption::getLinkedScreenID() {
	return linkedScreenID;
}

StringIdChatParameter& ConversationOption::getOptionText() {
	return optionText;
}

UnicodeString& ConversationOption::getCustomOption() {
	return customOption;
}

String ConversationOption::getDisplayedName() {
	if (customOption.isEmpty())
		return optionText.getFullPath();
	else
		return customOption.toString();
}

bool ConversationOption::isLinked() {
	return !linkedScreenID.isEmpty();
}

void ConversationOption::setOptionText(const StringIdChatParameter& optionText) {
	this->optionText = optionText;
}

ConversationScreen::ConversationScreen() {
	stopConversation = false;
	readOnly = false;
}

ConversationScreen::ConversationScreen(StringIdChatParameter dialogue, bool stopConv) {
	dialogText = dialogue;
	stopConversation = stopConv;
}

/**
 * Copy constructor.
 */
ConversationScreen::ConversationScreen(const ConversationScreen& objectToCopy) : Object() {
	screenID = objectToCopy.screenID;
	dialogText = objectToCopy.dialogText;
	options = objectToCopy.options;
	stopConversation = objectToCopy.stopConversation;
	readOnly = objectToCopy.readOnly;
	customText = objectToCopy.customText;
	animation = objectToCopy.animation;
	playerAnimation = objectToCopy.playerAnimation;
}

ConversationScreen* ConversationScreen::cloneScreen() {
	ConversationScreen* clone = new ConversationScreen(*this);
	clone->readOnly = false;

	return clone;
}

/**
 * Adds an option to this conversation screen.
 * @param optionText The text to be displayed for the option.
 * @param linkedScreenID The ID of the screen this option is linked.
 */
void ConversationScreen::addOption(const String& optionText, const String& linkedScreenID) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	if (optionText.beginsWith("@"))
		options.add(new ConversationOption(StringIdChatParameter(optionText), linkedScreenID));
	else
		options.add(new ConversationOption(UnicodeString(optionText), linkedScreenID));
}

void ConversationScreen::removeOption(int idx) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	options.remove(idx);
}

void ConversationScreen::removeAllOptions() {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	options.removeAll();
}

ConversationOption* ConversationScreen::getOption(int idx) {
	return options.get(idx);
}

String ConversationScreen::getOptionText(int idx) const {
	String text;

	Reference<ConversationOption*> opt = options.get(idx);

	if (opt != nullptr)
		text = opt->getOptionText().getFullPath();

	return text;
}

String ConversationScreen::getOptionLink(int idx) const {
	String link;

	Reference<ConversationOption*> opt = options.get(idx);

	if (opt != nullptr)
		link = opt->getLinkedScreenID();

	return link;
}

int ConversationScreen::getOptionCount() {
	return options.size();
}

/**
 * Sends this ConversationScreen to the creature passed in.
 * @param player The player receiving the message.
 * @param npc The npc the player is talking to.
 */
void ConversationScreen::sendTo(CreatureObject* player, SceneObject* npc) {
	NpcConversationMessage* message;

	if (customText.isEmpty())
		message = new NpcConversationMessage(player, dialogText);
	else
		message = new NpcConversationMessage(player, customText);

	// Encapsulate this logic better?
	StringList* optionsList = new StringList(player);

	for (int i = 0; i < options.size(); ++i) {
		Reference<ConversationOption*> option = options.get(i);

		if (option == nullptr)
			continue;

		optionsList->insertOption(option->getDisplayedName());
	}

	player->sendMessage(message);
	player->sendMessage(optionsList);

	CreatureObject* creo = npc->asCreatureObject();

	if (!animation.isEmpty() && creo != nullptr) {
		creo->doAnimation(animation);
	}

	if (!playerAnimation.isEmpty()) {
		player->doAnimation(playerAnimation);
	}

	ConversationScreen* screenToSave = this;

	// Check if the conversation should be stopped.
	if (stopConversation) {
		if (npc->isShipAiAgent()) {
			auto task = new SpaceCommTimerTask(player, npc->getObjectID());

			if (task != nullptr) {
				player->addPendingTask("SpaceCommTimer", task, 3000);
			}
		} else {
			player->sendMessage(new StopNpcConversation(player, npc->getObjectID()));
			npc->notifyObservers(ObserverEventType::STOPCONVERSATION, player);
		}

		screenToSave = nullptr;
	}

	Reference<ConversationSession*> session = player->getActiveSession(SessionFacadeType::CONVERSATION).castTo<ConversationSession*>();

	if (session != nullptr) {
		session->setLastConversationScreen(screenToSave);
	}
}

String& ConversationScreen::getScreenID() {
	return screenID;
}

void ConversationScreen::readObject(LuaObject* luaObject) {
	screenID = luaObject->getStringField("id");
	dialogText.setStringId(luaObject->getStringField("leftDialog"));
	customText = luaObject->getStringField("customDialogText");
	animation = luaObject->getStringField("animation");
	playerAnimation = luaObject->getStringField("playerAnimation");

	if (luaObject->getStringField("stopConversation").toLowerCase() == "true") {
		stopConversation = true;
	} else {
		stopConversation = false;
	}

	LuaObject optionsTable = luaObject->getObjectField("options");

	for (int i = 1; i <= optionsTable.getTableSize(); ++i) {
		lua_rawgeti(luaObject->getLuaState(), -1, i);

		LuaObject luaObj(luaObject->getLuaState());

		String optionString = luaObj.getStringAt(1);
		String linkedId = luaObj.getStringAt(2);

		Reference<ConversationOption*> option = nullptr;

		if (optionString.beginsWith("@"))
			option = new ConversationOption(StringIdChatParameter(optionString), linkedId);
		else
			option = new ConversationOption(UnicodeString(optionString), linkedId);

		options.add(option);

		luaObj.pop();
	}

	optionsTable.pop();

	readOnly = true;
}

void ConversationScreen::setDialogTextTT(const String& file, const String& id) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	dialogText.setTT(file, id);
}

void ConversationScreen::setDialogTextTO(const String& file, const String& id) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	dialogText.setTO(file, id);
}

void ConversationScreen::setDialogTextTU(const String& file, const String& id) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	dialogText.setTU(file, id);
}

void ConversationScreen::setDialogTextDI(uint32 val) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	dialogText.setDI(val);
}

void ConversationScreen::setDialogTextDF(float val) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	dialogText.setDF(val);
}

void ConversationScreen::setDialogText(const String& fullPath) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	dialogText.setStringId(fullPath);
}

void ConversationScreen::setCustomDialogText(const UnicodeString& custom) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	customText = custom;
}

void ConversationScreen::setDialogText(const StringIdChatParameter& param) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	dialogText = param;
}

void ConversationScreen::setStopConversation(bool stopConversation) {
	if (readOnly)
		throw Exception("Can't modify read only Conversation Screen!");

	this->stopConversation = stopConversation;
}

StringIdChatParameter* ConversationScreen::getDialogText() {
	return &dialogText;
}