#include "CancelCraftingSessionCommand.h"
#include "server/zone/objects/draftschematic/DraftSchematic.h"
#include "server/zone/objects/player/sessions/crafting/CraftingSession.h"

CancelCraftingSessionCommand::CancelCraftingSessionCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int CancelCraftingSessionCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return INVALIDTARGET;

	Reference<CraftingSession*> session = creature->getActiveSession(SessionFacadeType::CRAFTING).castTo<CraftingSession*>();

	if (session == nullptr) {
		return GENERALERROR;
	}

	Locker locker(session);
	session->cancelSessionCommand();

	return SUCCESS;
}