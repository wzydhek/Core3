/*
 * PaletteColorCustomizationVariables.h
 *
 *  Created on: 23-feb-2009
 *      Author: TheAnswer
 */

#pragma once

#include "templates/params/PaletteColorCustomizationVariable.h"
#include "templates/params/Param.h"

class PaletteColorCustomizationVariables : public Param {
protected:
	//QMap<QString, PaletteColorCustomizationVariable*> variables;
	Vector<PaletteColorCustomizationVariable*> variables;

public:
	PaletteColorCustomizationVariables();

	PaletteColorCustomizationVariables(const PaletteColorCustomizationVariables& p);

	~PaletteColorCustomizationVariables();

	String toString() const;

	void toString(String& str) const;

	bool parse(Chunk* source);

	void parseType1(IffStream* source);
};
