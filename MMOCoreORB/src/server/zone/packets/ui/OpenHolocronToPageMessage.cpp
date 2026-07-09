#include "OpenHolocronToPageMessage.h"

OpenHolocronToPageMessage::OpenHolocronToPageMessage(const String& page) : BaseMessage() {
	insertShort(0x09);
	insertInt(0x7CB65021); // CRC

	insertAscii(page);
	insertShort(0x00);
}