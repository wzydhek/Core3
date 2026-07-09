#include "PopulateMissionBrowserMessage.h"

PopulateMissionBrowserMessage::PopulateMissionBrowserMessage() : BaseMessage() {
	insertShort(3);
	insertInt(0x88D9885C);
	insertInt(0); // list begin?
}