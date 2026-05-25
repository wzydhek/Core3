/*
 * CustomizationDataMap.h
 *
 *  Created on: Feb 11, 2011
 *      Author: crush
 */

#pragma once

#include "templates/customization/CustomizationData.h"

class CustomizationDataMap : public VectorMap<String, Vector<CustomizationData>> {
public:
	CustomizationDataMap() {
		setNoDuplicateInsertPlan();
	}

	void parseFromIffStream(IffStream* iffStream) {
	}
};
