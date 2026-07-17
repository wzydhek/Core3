/*
 * PaletteColor.h
 *
 *  Created on: 19/03/2012
 *      Author: victor
 */

#pragma once

#include "system/lang/Object.h"
#include "system/io/ObjectInputStream.h"

namespace templates {
namespace appearance {

class PaletteColor : public Object {
	uint8 red;
	uint8 green;
	uint8 blue;
	uint8 unknown;

public:
	PaletteColor();

	PaletteColor(const PaletteColor& c);

	PaletteColor& operator=(const PaletteColor& c);

	void readObject(ObjectInputStream* stream);

	uint8 getRed();

	uint8 getGreen();

	uint8 getBlue();
};

} // namespace appearance
} // namespace templates

using namespace templates::appearance;
