/*
 * RadialFamily.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"

namespace terrain {

class RadialData {
public:
	String ascii; // + 8 4byte vars
	float var1;
	float var2;
	float var3;
	float var4;
	int var5;
	float var6;
	float var7;
	int var8;
	uint32 var9;
};

class RadialFamily : public TemplateVariable<'RFAM'> {
	int familyId;
	String familyName;
	byte red, green, blue;
	float weight;

	Vector<RadialData*> data;


public:
	~RadialFamily();

	void readObject(IffStream* iffStream);
};

} // namespace terrain

using namespace terrain;
