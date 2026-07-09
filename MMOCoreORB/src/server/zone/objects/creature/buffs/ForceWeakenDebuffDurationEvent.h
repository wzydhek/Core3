/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/creature/buffs/Buff.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace creature {
    namespace buffs {

		class ForceWeakenDebuffDurationEvent : public Task {
			ManagedWeakReference<CreatureObject*> creatureObject;
			ManagedWeakReference<Buff*> buffObject;

		public:
			ForceWeakenDebuffDurationEvent(CreatureObject* creature, Buff* buff);

			void run();

			void setBuffObject(Buff* buff);
		};
    }
   }
  }
 }
}

using namespace server::zone::objects::creature::buffs;
