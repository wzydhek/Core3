#include "ResourceHarvesterActivatePageMessage.h"

ResourceHarvesterActivatePageMessage::ResourceHarvesterActivatePageMessage(uint64 oid) : BaseMessage() {
	insertShort(0x02);
	insertInt(0xBD18C679); // CRC
	insertLong(oid);
}