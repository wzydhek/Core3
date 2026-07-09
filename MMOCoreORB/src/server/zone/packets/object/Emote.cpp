#include "Emote.h"

Emote::Emote(uint64 senderID, uint64 targetID, uint64 emoteTargetID, uint32 emoteID, bool doAnim, bool doText) : ObjectControllerMessage(targetID, 0x0B, 0x12E) {
	insertLong(senderID);
	insertLong(emoteTargetID);
	insertInt(emoteID);
	insertByte((doAnim ? 0x01 : 0) | (doText ? 0x02 : 0));
}