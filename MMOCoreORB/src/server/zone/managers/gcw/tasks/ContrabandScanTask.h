/*
 * ContrabandScanTask.h
 *
 *  Created on: Nov 3, 2016
 *      Author: loshult
 */

#pragma once

#include "server/zone/managers/gcw/sessions/ContrabandScanSession.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ContrabandScanTask : public Task {
	WeakReference<CreatureObject*> weakPlayer;

public:
	ContrabandScanTask(CreatureObject* player) {
		weakPlayer = player;
	}

	void run() {
		ManagedReference<CreatureObject*> player = weakPlayer.get();

		if (player != nullptr) {
			Locker locker(player);
			ManagedReference<ContrabandScanSession*> scanSession = player->getActiveSession(SessionFacadeType::CONTRABANDSCAN).castTo<ContrabandScanSession*>();
			if (scanSession != nullptr) {
				scanSession->runContrabandScan();
			}
		}
	}
};
