/*
 * DataStorageUnitDataComponent.h
 *
 *  Created on: 11/8/2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace generic {

class DataStorageUnitDataComponent : public DataObjectComponent {
protected:
	byte id;
public:
	DataStorageUnitDataComponent();

	virtual ~DataStorageUnitDataComponent();

	void writeJSON(nlohmann::json& j) const;

	byte getId() const;

	bool isDataStorageUnitData();

private:
	void addSerializableVariables();
};

} // namespace generic
} // namespace components
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::components::generic;
