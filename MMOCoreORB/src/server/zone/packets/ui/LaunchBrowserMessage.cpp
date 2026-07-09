#include "LaunchBrowserMessage.h"

LaunchBrowserMessage::LaunchBrowserMessage(const String& url) : BaseMessage() {
	insertShort(0x02);
	insertInt(0x8DE7E213); // CRC

	insertAscii(url); // url. minus the http.
}