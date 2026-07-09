#include "TicketSelectionSuiCallback.h"

TicketSelectionSuiCallback::TicketSelectionSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void TicketSelectionSuiCallback::run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	//@travel:boarding_ticket_selecting You must select a ticket to use before boarding.
	//@travel:wrong_shuttle This ticket is not valid for the given shuttle.
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isListBox() || cancelPressed)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	SuiListBox* listBox = cast<SuiListBox*>(sui);

	if (index < 0 || index >= listBox->getMenuSize())
		return;

	uint64 ticketID = listBox->getMenuObjectID(index);

	player->executeObjectControllerAction(0x5DCD41A2, ticketID, "");
}