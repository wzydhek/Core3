/*
 * CustomizationIdManager.h
 *
 *  Created on: 28/03/2012
 *      Author: victor
 */

#pragma once

#include "engine/log/Logger.h"
#include "engine/util/Singleton.h"
#include "templates/customization/PaletteData.h"
#include "templates/customization/HairAssetData.h"

namespace templates {
namespace customization {

class CustomizationIdManager : public Object, public Logger, public Singleton<CustomizationIdManager> {
	HashTable<String, int> customizationIds;
	HashTable<int, String> reverseIds;
	HashTable<String, Reference<PaletteData*> > paletteColumns;
	HashTable<String, Reference<HairAssetData*> > hairAssetSkillMods;
	HashTable<int, bool> allowBald;

public:
	CustomizationIdManager();

	void loadPaletteColumns(IffStream* iffStream);
	void loadHairAssetsSkillMods(IffStream* iffStream);
	void loadAllowBald(IffStream* iffStream);
	void readObject(IffStream* iffStream);

	int getCustomizationId(const String& var);

	String getCustomizationVariable(int id);

	PaletteData* getPaletteData(const String& palette);

	HairAssetData* getHairAssetData(const String& hairServerTemplate);

	bool canBeBald(const int objectCRC);
};

} // namespace customization
} // namespace templates

using namespace templates::customization;
