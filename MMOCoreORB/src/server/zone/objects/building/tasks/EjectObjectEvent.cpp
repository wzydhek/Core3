#include "EjectObjectEvent.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"

EjectObjectEvent::EjectObjectEvent(SceneObject* obj, float x, float z, float y) {
	object = obj;
	this->x = x, this->y = y, this->z = z;
}

void EjectObjectEvent::run() {
	Locker locker(object);

	if (object->isCreatureObject()) {
		StringBuffer msg;
		msg << "EjectObjectEvent(" << object->getObjectID() << ", x:" << x << ", z:" << z << ", y:" << y << ")"
			<< " from " << object->getWorldPosition().toString();
		;

		auto creo = object->asCreatureObject();

		if (creo != nullptr) {
			creo->info(msg.toString());

			if (creo->isPlayerCreature()) {
				PlayerObject* ghost = creo->getPlayerObject();

				if (ghost != nullptr) {
					ghost->setForcedTransform(true);
				}
			}
		} else {
			object->info(msg.toString());
		}
	}
	object->teleport(x, z, y);
	object->updateZone(true, true);
}