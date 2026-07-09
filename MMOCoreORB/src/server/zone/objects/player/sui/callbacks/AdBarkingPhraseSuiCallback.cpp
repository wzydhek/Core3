#include "AdBarkingPhraseSuiCallback.h"

AdBarkingPhraseSuiCallback::AdBarkingPhraseSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void AdBarkingPhraseSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	ManagedReference<VendorAdBarkingSession*> session = creature->getActiveSession(SessionFacadeType::VENDORADBARKING).castTo<VendorAdBarkingSession*>();

	if (session == nullptr) {
		return;
	}

	if (sui->getWindowType() == SuiWindowType::VENDOR_PHRASES) {
		handleSelectPhrase(session.get(), creature, sui, cancelPressed, args);
	} else if (sui->getWindowType() == SuiWindowType::VENDOR_MOODS) {
		handleSelectMood(session, creature, sui, cancelPressed, args);
	} else if (sui->getWindowType() == SuiWindowType::VENDOR_CUSTOM_PHRASE) {
		handleCustomMessage(session, creature, sui, cancelPressed, args);
	} else if (sui->getWindowType() == SuiWindowType::VENDOR_ANIMATION) {
		handleSelectAnimation(session, creature, sui, cancelPressed, args);
	}
}

void AdBarkingPhraseSuiCallback::handleSelectPhrase(VendorAdBarkingSession* session, CreatureObject* creature, SuiBox* sui, bool cancelPressed, Vector<UnicodeString>* args) {
	SuiListBox* listBox = cast<SuiListBox*>(sui);
	int index = Integer::valueOf(args->get(0).toString());

	if (cancelPressed || listBox == nullptr || (index < 0 || index > 14)) {
		session->cancelSession();
		return;
	}

	int id = listBox->getMenuObjectID(index);

	if (id == 0) {
		session->sendCustomMessageInput();
		return;
	}

	String type = listBox->getMenuItemName(index).replaceFirst("@map_loc_cat_n:vendor_", "");
	session->setMessage("@player_structure:areabark_" + type);
}

void AdBarkingPhraseSuiCallback::handleCustomMessage(VendorAdBarkingSession* session, CreatureObject* creature, SuiBox* sui, bool cancelPressed, Vector<UnicodeString>* args) {
	SuiInputBox* inputBox = cast<SuiInputBox*>(sui);

	if (cancelPressed || inputBox == nullptr) {
		session->sendPhraseOptions();
		return;
	}

	auto zoneServer = creature->getZoneServer();

	if (zoneServer == nullptr) {
		session->sendPhraseOptions();
		return;
	}

	auto nameManager = zoneServer->getNameManager();

	if (nameManager == nullptr) {
		session->sendPhraseOptions();
		return;
	}

	String message = args->get(0).toString();

	if (nameManager->isProfane(message)) {
		session->sendPhraseOptions();
		creature->sendSystemMessage("Phrase rejected by filter, please try again");
		return;
	}

	session->setMessage(message);
}

void AdBarkingPhraseSuiCallback::handleSelectMood(VendorAdBarkingSession* session, CreatureObject* creature, SuiBox* sui, bool cancelPressed, Vector<UnicodeString>* args) {
	SuiListBox* listBox = cast<SuiListBox*>(sui);

	int index = Integer::valueOf(args->get(0).toString());

	if (cancelPressed || listBox == nullptr || index < 0) {
		session->sendPhraseOptions();
		return;
	}

	String mood = listBox->getMenuItemName(index);

	if (mood.contains("@player_structure:")) {
		mood = mood.replaceFirst("@player_structure:", "");
	} else {
		mood = mood.replaceFirst("@event_perk_npc_actor:", "");
	}

	session->setMood(mood);
}

void AdBarkingPhraseSuiCallback::handleSelectAnimation(VendorAdBarkingSession* session, CreatureObject* creature, SuiBox* sui, bool cancelPressed, Vector<UnicodeString>* args) {
	SuiListBox* listBox = cast<SuiListBox*>(sui);

	int index = Integer::valueOf(args->get(0).toString());

	if (cancelPressed || listBox == nullptr || index < 0) {
		session->sendPhraseOptions();
		return;
	}

	String animation = listBox->getMenuItemName(index);

	if (animation.contains("@player_structure:")) {
		animation = animation.replaceFirst("@player_structure:", "");
	} else {
		animation = animation.replaceFirst("@event_perk_npc_actor:", "");
	}

	session->setAnimation(animation);
}