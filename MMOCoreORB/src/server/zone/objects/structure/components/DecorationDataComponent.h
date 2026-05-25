/*
 * DecorationDataComponent.h
 *
 *  Created on: Apr 9, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

class DecorationDataComponent : public DataObjectComponent {
protected:


public:
	DecorationDataComponent() {

	}

	virtual ~DecorationDataComponent() {

	}

	bool isDecoration() {
		return true;
	}

};
