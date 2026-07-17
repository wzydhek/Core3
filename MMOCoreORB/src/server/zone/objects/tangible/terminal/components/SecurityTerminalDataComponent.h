/*
 * SecurityTerminalDataComponent.h
 *
 *  Created on: Dec 10, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace components {

class SecurityTerminalDataComponent : public DataObjectComponent {
protected:


public:
	SecurityTerminalDataComponent();

	virtual ~SecurityTerminalDataComponent();

	bool isSecurityTerminalData();

};

} // namespace components
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::components;
