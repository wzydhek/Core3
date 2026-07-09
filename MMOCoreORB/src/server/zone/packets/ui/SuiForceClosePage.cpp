#include "SuiForceClosePage.h"

SuiForceClosePage::SuiForceClosePage(uint32 pageID) : BaseMessage() {
	insertShort(0x02);
	insertInt(0x990B5DE0); // CRC

	insertInt(pageID);
}