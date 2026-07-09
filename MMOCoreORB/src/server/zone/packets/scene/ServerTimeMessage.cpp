#include "ServerTimeMessage.h"

ServerTimeMessage::ServerTimeMessage(uint64 time) : BaseMessage(18) {
	insertShort(0x02);
	insertInt(0x2EBC3BD9); // CRC
	insertLong(time);	   // Galactic_Time
}

ServerTimeMessage::ServerTimeMessage(Zone* zone) : BaseMessage(18) {
	insertShort(0x02);
	insertInt(0x2EBC3BD9);				 // CRC
	insertLong(zone->getGalacticTime()); // Galactic_Time
}