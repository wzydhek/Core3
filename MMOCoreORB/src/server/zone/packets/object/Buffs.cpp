#include "Buffs.h"

AddBuffMessage::AddBuffMessage(SceneObject* player, uint32 buffcrc, float duration) : ObjectControllerMessage(player->getObjectID(), 0x1B, 0x229, false) {
	insertInt(buffcrc);
	insertFloat(duration);
}

RemoveBuffMessage::RemoveBuffMessage(CreatureObject* player, uint32 buffcrc) : ObjectControllerMessage(player->getObjectID(), 0x1B, 0x22A, false) {
	insertInt(buffcrc);
}