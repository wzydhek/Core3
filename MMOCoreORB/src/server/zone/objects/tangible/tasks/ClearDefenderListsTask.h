/*
 * ClearDefenderLists.h
 *
 *  Created on: 10/04/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {
class SceneObject;
}
namespace tangible {
namespace tasks {

class ClearDefenderListsTask : public Task {
	DeltaVector<ManagedReference<SceneObject* > > defenderList;
	ManagedReference<TangibleObject*> tangibleObject;
public:
	ClearDefenderListsTask(const DeltaVector<ManagedReference<SceneObject*>>& list, TangibleObject* tano);

	void run();
};

} // namespace tasks
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::tasks;
