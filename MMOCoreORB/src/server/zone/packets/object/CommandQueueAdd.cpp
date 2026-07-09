#include "CommandQueueAdd.h"

CommandQueueAdd::CommandQueueAdd(CreatureObject* creo, uint32 actionCRC, uint32 actioncnt) : ObjectControllerMessage(creo->getObjectID(), 0x0B, 0x167) {
	insertInt(actioncnt);
	insertInt(actionCRC);
}