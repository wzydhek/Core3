/*
 * DespawnCreatureOnPlayerDissappear.h
 *
 *  Created on: 13/07/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/creature/ai/AiAgent.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace creature {
    namespace events {


class DespawnCreatureOnPlayerDissappear : public Task {
	ManagedWeakReference<AiAgent*> creature;

public:
	DespawnCreatureOnPlayerDissappear(AiAgent* creo);

	void run();
};


    }
   }
  }
 }
}

using namespace server::zone::objects::creature::events;
