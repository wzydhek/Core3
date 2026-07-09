#include "ExecuteConsoleCommand.h"

ExecuteConsoleCommand::ExecuteConsoleCommand(const String& com) : BaseMessage() {
	insertShort(0x01);
	insertInt(0xB1CFCE1C); // CRC

	insertAscii(com); // Command to execute. With slash. Multiple commands seperated by ;
}