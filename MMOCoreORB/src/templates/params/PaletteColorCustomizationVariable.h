/*
 * PaletteColorCustomizationVariable.h
 *
 *  Created on: 23-feb-2009
 *      Author: TheAnswer
 */

#pragma once

#include "templates/params/RangedIntCustomizationVariable.h"

class PaletteColorCustomizationVariable : public RangedIntCustomizationVariable {
protected:
	StringParam palettePathName;

public:
	PaletteColorCustomizationVariable();

	PaletteColorCustomizationVariable(int defIndex, const String& fileName);

	PaletteColorCustomizationVariable(const PaletteColorCustomizationVariable& p);

	~PaletteColorCustomizationVariable();

	PaletteColorCustomizationVariable& operator=(const PaletteColorCustomizationVariable& p);

	String toString() const;

	bool parse(Chunk* source);


	const String& getPaletteFileName() const;

	/*static bool parseFromString(T* address, const sys::lang::String& value, int version = 0) {
		return address->parseFromString(value, version);
	}*/

	const String& getVariableName() const;

};
