#include "CreateManfSchematicCommand.h"
#include "server/zone/objects/player/sessions/crafting/CraftingSession.h"
#include "server/zone/objects/draftschematic/DraftSchematic.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/player/sessions/TradeSession.h"

CreateManfSchematicCommand::CreateManfSchematicCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int CreateManfSchematicCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
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

	StringTokenizer tokenizer(arguments.toString());
	int clientCounter = 0;

	if (tokenizer.hasMoreTokens())
		clientCounter = tokenizer.getIntToken();
	else
		return GENERALERROR;

	Reference<CraftingSession*> session = creature->getActiveSession(SessionFacadeType::CRAFTING).castTo<CraftingSession*>();

	if (session == nullptr) {
		warning("Trying to create manf schematic when no session exists");
		return GENERALERROR;
	}

	Locker locker(session);
	session->createManufactureSchematic(clientCounter);

	return SUCCESS;
}