/*
 * ExecuteConsoleCommand.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

class ExecuteConsoleCommand : public BaseMessage {
public:
   ExecuteConsoleCommand(const String& com) : BaseMessage() {
		insertShort(0x01);
		insertInt(0xB1CFCE1C);  // CRC

		insertAscii(com); //Command to execute. With slash. Multiple commands seperated by ;

   }

};
