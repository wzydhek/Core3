#include "CloseLotteryWindow.h"

CloseLotteryWindow::CloseLotteryWindow(CreatureObject* creo, SceneObject* inventory) : ObjectControllerMessage(creo->getObjectID(), 0x0B, 0x43D) {
	insertLong(inventory->getObjectID());
}