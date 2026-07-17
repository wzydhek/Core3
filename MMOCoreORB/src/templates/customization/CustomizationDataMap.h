/*
 * CustomizationDataMap.h
 *
 *  Created on: Feb 11, 2011
 *      Author: crush
 */

#pragma once

#include "templates/customization/CustomizationData.h"

namespace templates {
namespace customization {

class CustomizationDataMap : public VectorMap<String, Vector<CustomizationData>> {
public:
	CustomizationDataMap();

	void parseFromIffStream(IffStream* iffStream);
};

} // namespace customization
} // namespace templates

using namespace templates::customization;
