/*
 * FloraFamily.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"

class FloraData {
public:
	String name; // + 8 4byte vars
	float var1;
	uint32 var2;
	float var3;
	float var4;
	uint32 var5;
	int var6;
	float var7;
	float var8;
};

class FloraFamily : public TemplateVariable<'FFAM'> {
	int familyId;
	String familyName;
	byte red, green, blue;
	float weight;
	uint32 isAquatic;

	Vector<FloraData*> data;


public:
	~FloraFamily();

	void readObject(IffStream* iffStream);
};
