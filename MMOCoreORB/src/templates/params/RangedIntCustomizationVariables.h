/*
 * RangedIntCustomizationVariables.h
 *
 *  Created on: 16-abr-2009
 *      Author: TheAnswer
 */

#pragma once

#include "engine/util/iffstream/IffStream.h"
#include "templates/params/RangedIntCustomizationVariable.h"

namespace templates {
namespace params {

class RangedIntCustomizationVariables : public Param {
protected:
	//QMap<QString, PaletteColorCustomizationVariable*> variables;
	Vector<RangedIntCustomizationVariable*> variables;


public:
	RangedIntCustomizationVariables();

	~RangedIntCustomizationVariables();

	String toString() const;

	void toString(String& str);

	bool parse(Chunk* source);

	void parseType1(IffStream* source);
};

} // namespace params
} // namespace templates

using namespace templates::params;
