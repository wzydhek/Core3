/*
 * LogoutMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

class LogoutMessage : public BaseMessage {
public:
   LogoutMessage() : BaseMessage() {
		insertShort(0x01);
		insertInt(0x42FD19DD);  // CRC

		//Logs out the player.
   }

};
