/*
 * Layers.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "layer/Layer.h"

class LayersGroup : public TemplateVariable<'LYRS'> {
	Vector<Layer*> layers;
public:

	LayersGroup();

	~LayersGroup();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);

	Vector<Layer*>* getLayers();

	const Vector<Layer*>* getLayers() const;
};
