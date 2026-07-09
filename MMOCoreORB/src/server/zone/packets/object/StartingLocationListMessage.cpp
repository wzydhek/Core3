#include "StartingLocationListMessage.h"

StartingLocationListMessage::StartingLocationListMessage(CreatureObject* creo) : ObjectControllerMessage(creo->getObjectID(), 0x1B, 0x1FC) {
	// Populate with PlayerManager::sendStartingLocationListTo()
}