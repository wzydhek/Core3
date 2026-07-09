/*
 * SecurityTerminalDataComponent.h
 *
 *  Created on: Dec 10, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

class SecurityTerminalDataComponent : public DataObjectComponent {
protected:


public:
	SecurityTerminalDataComponent();

	virtual ~SecurityTerminalDataComponent();

	bool isSecurityTerminalData();

};
