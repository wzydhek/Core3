/*
 * BuildingDataComponent.h
 *
 *  Created on: Oct 22, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace components {

class BuildingDataComponent : public DataObjectComponent {
public:
	BuildingDataComponent();

	virtual ~BuildingDataComponent();

	virtual bool isGCWBaseData();

	bool isBuildingData();
};

} // namespace components
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::components;
