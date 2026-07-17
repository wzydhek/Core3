/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace scene {
	   class SceneObject;
   }
  }
 }
}

using namespace server::zone::objects::scene;

namespace server {
 namespace zone {
  namespace objects {
   namespace creature {
	   class CreatureObject;
   }
  }
 }
}

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {
	class QueueCommand;
}
}
}
}
}

using namespace server::zone::objects::creature::commands;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace variables {

class CommandQueueAction : public Object {
	ManagedReference<CreatureObject*> creature;
	uint64 target;
	uint32 queueCommand;

	uint32 actionCounter;

	UnicodeString arguments;

	int compareToCounter;

public:
	CommandQueueAction(CreatureObject* cr, uint64 tar, uint32 command, uint32 acntr, const UnicodeString& amod);

	void run();

	void clearError(uint32 tab1, uint32 tab2 = 0);

	void clear(float timer, uint32 tab1 = 0, uint32 tab2 = 0);

	int compareTo(CommandQueueAction* action);

	void setCompareToCounter(int c);

	int getCompareToCounter();

	CreatureObject* getCreature();

	uint32 getCommand();

	uint64 getTarget();

	uint32 getActionCounter();

	UnicodeString getArguments();

};

} // namespace variables
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::variables;
