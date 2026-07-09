#include "StopNpcConversation.h"

StopNpcConversation::StopNpcConversation(CreatureObject* creo, uint64 npcID) : ObjectControllerMessage(creo->getObjectID(), 0x0B, 0xDE, false) {
	insertLong(npcID);
}