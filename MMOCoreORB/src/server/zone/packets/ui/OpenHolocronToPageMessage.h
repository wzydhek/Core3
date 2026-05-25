/*
 * OpenHolocronToPageMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

class OpenHolocronToPageMessage : public BaseMessage {
public:
   OpenHolocronToPageMessage(const String& page) : BaseMessage() {
		insertShort(0x09);
		insertInt(0x7CB65021);  // CRC

		insertAscii(page);
		insertShort(0x00);
   }
};
