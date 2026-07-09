#include "EnterTicketPurchaseModeMessage.h"

EnterTicketPurchaseModeMessage::EnterTicketPurchaseModeMessage(PlanetTravelPoint* ptp) {
	insertShort(0x04);
	insertInt(0x904DAE1A); // CRC
	insertAscii(ptp->getPointZone());
	insertAscii(ptp->getPointName());
	insertByte(0);
}