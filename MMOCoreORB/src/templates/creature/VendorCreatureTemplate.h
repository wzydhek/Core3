/*
 * VendorCreatureTemplate.h
 *
 *  Created on: Mar 22, 2011
 *      Author: polonel
 */

#pragma once

#include "templates/creature/SharedCreatureObjectTemplate.h"

namespace templates {
namespace creature {

class VendorCreatureTemplate : public SharedCreatureObjectTemplate {
	Vector<String> outfits;
	Vector<String> hairFile;
	Vector<String> customizationStringNames;
	Vector<Vector<int> > customizationValues;

public:
	VendorCreatureTemplate();

	~VendorCreatureTemplate();

	void readObject(LuaObject* templateData);

	String getHairFile(int idx);

	String getOutfitName(int idx);

	int getCustomizationStringNamesSize();

	String getCustomizationStringName(int idx);

	int getCustomizationValuesSize();

	Vector<int> getCustomizationValues(int idx);

	int getOutfitsSize();

	int getHairSize();

	bool isVendorCreatureTemplate();

};

} // namespace creature
} // namespace templates

using namespace templates::creature;
