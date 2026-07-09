#include "CraftingCustomizationCallback.h"
#include "server/zone/objects/player/sessions/crafting/CraftingSession.h"
#include "server/zone/objects/draftschematic/DraftSchematic.h"
#include "server/zone/objects/creature/CreatureObject.h"

CraftingCustomizationCallback::CraftingCustomizationCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), schematicCount(0), counter(0), templateChoice(0), objectControllerMain(objectControllerCallback) {
}

void CraftingCustomizationCallback::parse(Message* message) {
	// System::out << message->toStringData() << endl;
	message->parseInt();

	UnicodeString n;
	message->parseUnicode(n);

	name = n.toString();

	templateChoice = message->parseByte();

	schematicCount = message->parseInt();

	counter = message->parseByte();

	int value, count;

	StringBuffer ss;

	for (int i = 0; i < counter; ++i) {
		count = message->parseInt();

		value = message->parseInt();

		ss << count << " " << value;

		if (i < counter - 1)
			ss << " ";
	}

	customizationString = ss.toString();
}

void CraftingCustomizationCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	Reference<CraftingSession*> session = player->getActiveSession(SessionFacadeType::CRAFTING).castTo<CraftingSession*>();

	if (session == nullptr) {
		warning("Trying to customize when no session exists");
		return;
	}

	Locker locker(session);
	session->customization(name, templateChoice, schematicCount, customizationString);
}