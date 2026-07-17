/*
 * DataObjectComponent.h
 *
 *  Created on: 18/03/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace components {
namespace generic {

class DiceDataComponent : public DataObjectComponent {
protected:
	byte sides;
public:
	DiceDataComponent();

	virtual ~DiceDataComponent();

	void writeJSON(nlohmann::json& j) const;

	void setSides(byte count);

	byte getSides() const;

	bool isDiceData();

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
