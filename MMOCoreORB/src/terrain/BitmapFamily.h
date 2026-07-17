/*
 * BitmapFamily.h
 *
 *  Created on: 06/09/2013
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"
#include "TargaBitmap.h"

namespace terrain {

class BitMapFamily : public TemplateVariable<'MFAM'> {
	int var1;
	String name;
	String file;

	TargaBitmap map;

public:
	BitMapFamily();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	TargaBitmap* getMap();

	const String& getName() const;

	int getVar1() const;

	const String& getFile() const;
};

} // namespace terrain

using namespace terrain;