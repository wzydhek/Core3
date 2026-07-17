/*
 * DecorationDataComponent.h
 *
 *  Created on: Apr 9, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace structure {
namespace components {

class DecorationDataComponent : public DataObjectComponent {
protected:
public:
	DecorationDataComponent();

	virtual ~DecorationDataComponent();

	bool isDecoration();
};

} // namespace components
} // namespace structure
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::structure::components;
