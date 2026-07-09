#include "CraftingAddIngredientCallback.h"
#include "server/zone/objects/draftschematic/DraftSchematic.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sessions/crafting/CraftingSession.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/player/sessions/TradeSession.h"

CraftingAddIngredientCallback::CraftingAddIngredientCallback(ObjectControllerMessageCallback* objectControllerCallback) : MessageCallback(objectControllerCallback->getClient(), objectControllerCallback->getServer()), objectID(0), slot(0), counter(0), objectControllerMain(objectControllerCallback) {
}

void CraftingAddIngredientCallback::parse(Message* message) {
	// Logger::console.info(true) << "Raw Message: " << message->toStringData();

	message->parseInt();

	objectID = message->parseLong();

	slot = message->parseInt();

	message->parseInt();

	counter = message->parseByte();
}

void CraftingAddIngredientCallback::run() {
	ManagedReference<CreatureObject*> player = client->getPlayer();

	if (player == nullptr)
		return;

	Reference<CraftingSession*> session = player->getActiveSession(SessionFacadeType::CRAFTING).castTo<CraftingSession*>();

	if (session == nullptr) {
		// warning("Trying to add an ingredient when no session exists");
		return;
	}

	if (session->getState() > 2) {
		// warning("Trying to add an ingredient when the item is already assembled");
		return;
	}

	ManagedReference<TradeSession*> tradeContainer = player->getActiveSession(SessionFacadeType::TRADE).castTo<TradeSession*>();

	if (tradeContainer != nullptr) {
		server->getZoneServer()->getPlayerManager()->handleAbortTradeMessage(player);
	}

	ManagedReference<SceneObject*> object = player->getZoneServer()->getObject(objectID);

	if (object == nullptr || !object->isTangibleObject()) {
		player->sendSystemMessage("@ui_craft:err_invalid_ingredient");
		return;
	}

	Locker locker(session);
	TangibleObject* tano = cast<TangibleObject*>(object.get());
	session->addIngredient(tano, slot, counter);
}