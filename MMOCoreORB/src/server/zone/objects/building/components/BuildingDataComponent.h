/*
 * BuildingDataComponent.h
 *
 *  Created on: Oct 22, 2012
 *      Author: root
 */

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"

class BuildingDataComponent : public DataObjectComponent {

public:
	BuildingDataComponent(){
	}

	virtual ~BuildingDataComponent(){
	}

	virtual bool isGCWBaseData(){
		return false;
	}

	bool isBuildingData(){
		return true;
	}
};
