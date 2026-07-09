/*
 * ChatParameter.cpp
 *
 *  Created on: Nov 9, 2010
 *      Author: crush
 */

#include "ChatParameter.h"

ChatParameter::ChatParameter() {
}

ChatParameter::ChatParameter(const ChatParameter& cp) : Object() {
}

ChatParameter& ChatParameter::operator=(const ChatParameter& id) {
	if (&id == this)
		return *this;

	return *this;
}

void ChatParameter::insertToMessage(Message* message) const {
	int offset = message->getOffset();

	message->insertShort(0);

	insertHeaderToMessage(message);

	addToPacketStream(message);

	if ((message->getOffset() - offset) & 1) {
		message->insertByte(0);
		message->insertShort(offset, 1);
	}
}

void ChatParameter::insertHeaderToMessage(Message* message) const {
	message->insertByte(TYPE_STRINGID);
	message->insertInt(STRINGID);
}

bool ChatParameter::isStringIdParameter() {
	return false;
}

bool ChatParameter::isWaypointParameter() {
	return false;
}