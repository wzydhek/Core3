#include "ObjCtrlMessageQueueString.h"

ObjCtrlMessageQueueString::ObjCtrlMessageQueueString(SceneObject* creo, const String& data, uint32 type) : ObjectControllerMessage(creo->getObjectID(), 0x1B, type, false) {
	insertAscii(data.toCharArray());
}