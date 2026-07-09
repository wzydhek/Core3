#include "PostureMessage.h"

PostureMessage::PostureMessage(CreatureObject* creo) : ObjectControllerMessage(creo->getObjectID(), 0x1B, 0x131) {
	insertByte(creo->getPosture());
	insertByte(0x01);
}