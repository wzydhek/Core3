/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/tangible/components/vendor/VendorDataComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace auction {
namespace events {

class UpdateVendorTask: public Task {
protected:
	ManagedWeakReference<SceneObject*> vendor;

public:
	UpdateVendorTask(SceneObject* vndr);

	void run();

};

}
}
}
}
}

using namespace server::zone::objects::auction::events;
