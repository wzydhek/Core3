#include "LayersGroup.h"

LayersGroup::LayersGroup() {
}

LayersGroup::~LayersGroup() {
	for (int i = 0; i < layers.size(); ++i)
		delete layers.get(i);

	layers.removeAll();
}

void LayersGroup::parseFromIffStream(engine::util::IffStream* iffStream) {
	uint32 version = iffStream->getNextFormType();

	parseFromIffStream(iffStream, Version<'0000'>());
}

void LayersGroup::parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>) {
	int number = iffStream->getSubChunksNumber();

	for (int i = 0; i < number; ++i) {
		Layer* layer = new Layer();
		layer->readObject(iffStream);

		layers.add(layer);
	}
}

Vector<Layer*>* LayersGroup::getLayers() {
	return &layers;
}

const Vector<Layer*>* LayersGroup::getLayers() const {
	return &layers;
}