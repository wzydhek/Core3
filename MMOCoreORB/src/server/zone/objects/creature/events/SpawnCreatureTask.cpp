#include "SpawnCreatureTask.h"

SpawnCreatureTask::SpawnCreatureTask(uint32 temp, float resp, String zone, float xPos, float zPos, float yPos, uint64 par, bool rand) {
	templateCRC = temp;
	respawn = resp;
	zoneName = zone;
	x = xPos;
	z = zPos;
	y = yPos;
	parentID = par;
	randomRespawn = rand;
}

void SpawnCreatureTask::run() {
	ZoneServer* zoneServer = ServerCore::getZoneServer();
	Zone* zone = zoneServer->getZone(zoneName);

	if (zone == nullptr)
		return;

	CreatureObject* creature = zone->getCreatureManager()->spawnCreature(templateCRC, 0, x, z, y, parentID);

	if (creature->isAiAgent()) {
		AiAgent* ai = cast<AiAgent*>(creature);

		Locker locker(ai);

		ai->setRespawnTimer(respawn);

		if (randomRespawn)
			ai->setRandomRespawn(true);

		ai->addObjectFlag(ObjectFlag::STATIC);
		ai->setAITemplate();
	}
}