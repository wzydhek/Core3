
#pragma once

#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/tangible/eventperk/Jukebox.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tasks {

class RemoveEventPerkItemTask : public Task {
	ManagedWeakReference<TangibleObject*> tano;

public:
	RemoveEventPerkItemTask(TangibleObject* obj);

	void run();
};

}
}
}
}
}

using namespace server::zone::objects::tangible::tasks;
