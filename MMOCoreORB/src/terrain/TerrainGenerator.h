/*
 * TerrainGenerator.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"
#include "ShadersGroup.h"
#include "RadialGroup.h"
#include "FloraGroup.h"
#include "EnvironmentGroup.h"
#include "MapGroup.h"
#include "LayersGroup.h"
#include "layer/Layer.h"
#include "BitmapGroup.h"

namespace terrain {

class ProceduralTerrainAppearance;

class TerrainGenerator : public TemplateVariable<'TGEN'> {
	ProceduralTerrainAppearance* terrain;

	ShadersGroup shaderGroup;
	RadialGroup radialGroup;
	FloraGroup floraGroup;
	EnvironmentGroup environmentGroup;
	MapGroup mapGroup;
	BitmapGroup bitmapGroup;
	LayersGroup layers;

public:
	TerrainGenerator(ProceduralTerrainAppearance* ptat);

	void processLayers();
	void processLayer(Layer* layer);

	void parseFromIffStream(engine::util::IffStream* iffStream);
	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);

	void addLayer(Layer* layer);
	void removeLayer(Layer* layer);

	bool getFullBoundaryCircle(float& centerX, float& centerY, float& radius) const;

	void getFullBoundaryCircle(const Layer* layer, float& minX, float& minY, float& maxX, float& maxY) const;

	MapGroup* getMapGroup();

	LayersGroup* getLayersGroup();

	BitmapGroup* getBitmapGroup();

	MapFractal* getMfrc(int idx);

	const MapGroup* getMapGroup() const;

	const LayersGroup* getLayersGroup() const;

	const BitmapGroup* getBitmapGroup() const;

	const MapFractal* getMfrc(int idx) const;

};

} // namespace terrain

using namespace terrain;
