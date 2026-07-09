/*
 * TerrainMap.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"

template<int chunkType>
class TerrainMap : public TemplateVariable<chunkType> {
	byte* rawMap;

public:
	TerrainMap() {
		rawMap = nullptr;
	}

	~TerrainMap() {
		delete[] rawMap;
		rawMap = nullptr;
	}

	void readObject(engine::util::IffStream* iffStream) {
		if (rawMap != nullptr)
			delete rawMap;

		iffStream->openChunk(chunkType);

		int size = iffStream->getDataSize();

		rawMap = new byte[size];
		iffStream->getBytes(size, rawMap);

		iffStream->closeChunk(chunkType);
	}

	const byte* getMap() const {
		return rawMap;
	}
};
