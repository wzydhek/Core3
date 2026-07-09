/*
 * RecruitSkillTrainer.h
 *
 *  Created on: Apr. 26 2012
 *      Author: TragD
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"

class RecruitSkillTrainerSuiCallback : public SuiCallback {
public:
	RecruitSkillTrainerSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
