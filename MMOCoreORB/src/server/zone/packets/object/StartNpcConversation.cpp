#include "StartNpcConversation.h"

StartNpcConversation::StartNpcConversation(CreatureObject* creo, uint64 npcID, byte starter, const String& ascii, uint32 crc) : ObjectControllerMessage(creo->getObjectID(), 0x0B, 0xDD) {
	insertLong(npcID);	 // LongID of Conversing NPC
	insertByte(starter); // Conversation Starter (0 - player or 1 - npc)
	insertAscii(ascii.toCharArray());
	insertInt(crc); // Mobile CRC for JTL convos
}