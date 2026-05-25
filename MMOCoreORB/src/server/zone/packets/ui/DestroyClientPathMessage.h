/*
 * DestroyClientPathMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

class DestroyClientPathMessage : public BaseMessage {
public:
   DestroyClientPathMessage() : BaseMessage() {
		insertShort(0x01);
		insertInt(0xA75E85EB);  // CRC

		//Destroys the path

   }

};
