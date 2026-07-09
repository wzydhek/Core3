/*
 * SpawnCreatureTask.h
 *
 *  Created on: 02/08/2015
 *      Author: Miztah
 */

#pragma once

#include "server/zone/Zone.h"
#include "server/ServerCore.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/managers/creature/CreatureManager.h"

class SpawnCreatureTask : public Task {
	uint32 templateCRC;
	float x, z, y, respawn;
	uint64 parentID;
	bool randomRespawn;
	String zoneName;

public:
	SpawnCreatureTask(uint32 temp, float resp, String zone, float xPos, float zPos, float yPos, uint64 par, bool rand);

	void run();
};
