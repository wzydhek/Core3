/*
 * RadialGroup.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "RadialFamily.h"

class RadialGroup : public TemplateVariable<'RGRP'> {
	Vector<RadialFamily*> data;
public:

	~RadialGroup();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0003'>);

};
