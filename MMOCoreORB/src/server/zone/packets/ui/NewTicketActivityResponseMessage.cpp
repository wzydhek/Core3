#include "NewTicketActivityResponseMessage.h"

NewTicketActivityResponseMessage::NewTicketActivityResponseMessage(byte flag, uint32 ticketid) : BaseMessage() {
	insertShort(0x03);
	insertInt(0x6EA42D80); // CRC

	insertByte(flag);	 //??
	insertInt(ticketid); // Probably the ticket id.
}

NewTicketActivityMessageCalback::NewTicketActivityMessageCalback(ZoneClientSession* client, ZoneProcessServer* server) : MessageCallback(client, server), ticketID(0) {
}

void NewTicketActivityMessageCalback::parse(Message* message) {
	ticketID = message->parseInt();
}

void NewTicketActivityMessageCalback::run() {
	NewTicketActivityResponseMessage* ntar = new NewTicketActivityResponseMessage(0, ticketID);
	client->sendMessage(ntar);
}