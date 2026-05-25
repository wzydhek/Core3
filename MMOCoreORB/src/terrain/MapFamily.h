/*
 * MapFamily.h
 *
 *  Created on: 02/02/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"
#include "MapFractal.h"

class MapFamily : public TemplateVariable<'MFAM'> {
	int var1;
	String var2;
	MapFractal mfrc;
public:
	MapFamily() : var1(0) {
	}

	void parseFromIffStream(engine::util::IffStream* iffStream) {
		iffStream->openChunk('DATA');

		var1 = iffStream->getInt();
		iffStream->getString(var2);

		iffStream->closeChunk('DATA');

		mfrc.readObject(iffStream);
	}

	inline MapFractal* getMfrc() {
		return &mfrc;
	}

	inline const MapFractal* getMfrc() const {
		return &mfrc;
	}

	inline int getVar1() const {
		return var1;
	}

	inline const String& getName() const {
		return var2;
	}
};
