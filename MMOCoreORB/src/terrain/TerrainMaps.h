/*
 * TerrainMaps.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"
#include "TerrainMap.h"

namespace terrain {

class TerrainMaps : public IffTemplateVariable {
	float var1;
	float var2;
	int var3;
	int var4;

	TerrainMap<'WMAP'> waterMap;
	TerrainMap<'SMAP'> seedMap;
public:
	void readObject(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);
};

} // namespace terrain

using namespace terrain;
