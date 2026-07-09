#include "ForagingEvent.h"

ForagingEvent::ForagingEvent(CreatureObject* player, int type, float playerX, float playerY, const String& planet) : Task() {
	this->player = player;
	this->forageType = type;
	this->forageX = playerX;
	this->forageY = playerY;
	this->zoneName = planet;
}

void ForagingEvent::run() {
	ManagedReference<ForageManager*> forageManager = player->getZoneProcessServer()->getForageManager();

	if (forageManager != nullptr)
		forageManager->finishForaging(player, forageType, forageX, forageY, zoneName);
}