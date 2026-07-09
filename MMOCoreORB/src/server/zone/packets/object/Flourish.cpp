#include "Flourish.h"

Flourish::Flourish(CreatureObject* creo, int flourishid) : ObjectControllerMessage(creo->getObjectID(), 0x1B, 0x166) {
	insertInt(flourishid);
}