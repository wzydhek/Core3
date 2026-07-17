/*
 * ShaderFamily.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"

namespace terrain {

class ShaderVar {
public:
	String name;
	float weight;
};

class ShaderFamily : public TemplateVariable<'SFAM'> {
	int familyId;
	String familyName;
	String fileName;
	byte red, green, blue;
	float var7;
	float weight;

	Vector<ShaderVar*> shaderVars;

public:
	~ShaderFamily();

	void readObject(IffStream* iffStream);
};

} // namespace terrain

using namespace terrain;
