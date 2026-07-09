#include "OpenLotteryWindow.h"

OpenLotteryWindow::OpenLotteryWindow(CreatureObject* creo, SceneObject* inventory) : ObjectControllerMessage(creo->getObjectID(), 0x0B, 0x43C) {
	insertLong(inventory->getObjectID());
}