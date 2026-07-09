/*
 * PalleteFile.h
 *
 *  Created on: 19/03/2012
 *      Author: victor
 */

#pragma once

#include "templates/appearance/PaletteColor.h"
#include "system/util/Vector.h"

class PaletteTemplate : public Object {
	Vector<PaletteColor> colors;
public:
	PaletteTemplate();

	void readObject(ObjectInputStream* stream);

	const Vector<PaletteColor>& getColors() const;

	int getColorCount() const;
};
