/*
 * MapFamily.h
 *
 *  Created on: 02/02/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"
#include "MapFractal.h"

namespace terrain {

class MapFamily : public TemplateVariable<'MFAM'> {
	int var1;
	String var2;
	MapFractal mfrc;
public:
	MapFamily();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	MapFractal* getMfrc();

	const MapFractal* getMfrc() const;

	int getVar1() const;

	const String& getName() const;
};

} // namespace terrain

using namespace terrain;