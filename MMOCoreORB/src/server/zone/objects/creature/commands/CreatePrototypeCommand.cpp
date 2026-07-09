#include "CreatePrototypeCommand.h"
#include "server/zone/objects/player/sessions/crafting/CraftingSession.h"
#include "server/zone/objects/draftschematic/DraftSchematic.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/player/sessions/TradeSession.h"

CreatePrototypeCommand::CreatePrototypeCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int CreatePrototypeCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	/**
	 * Arguments
	 *
	 * 1 Unicode String
	 * Contains clientCounter and int for practice
	 *
	 */

	if (!creature->isPlayerCreature())
		return INVALIDTARGET;

	ManagedReference<TradeSession*> tradeContainer = creature->getActiveSession(SessionFacadeType::TRADE).castTo<TradeSession*>();

	if (tradeContainer != nullptr) {
		server->getZoneServer()->getPlayerManager()->handleAbortTradeMessage(creature);
	}

	ManagedReference<CreatureObject*> player = cast<CreatureObject*>(creature);

	int clientCounter;
	bool createItem;

	StringTokenizer tokenizer(arguments.toString());

	if (tokenizer.hasMoreTokens())
		clientCounter = tokenizer.getIntToken();
	else
		clientCounter = 0;

	if (tokenizer.hasMoreTokens())
		createItem = tokenizer.getIntToken();
	else
		createItem = true;

	Reference<CraftingSession*> session = creature->getActiveSession(SessionFacadeType::CRAFTING).castTo<CraftingSession*>();

	if (session == nullptr) {
		return GENERALERROR;
	}

	if (session->getState() != 6)
		return GENERALERROR;

	Locker locker(session);
	session->createPrototype(clientCounter, createItem);

	return SUCCESS;
}