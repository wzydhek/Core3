/*
 * FloraGroup.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "FloraFamily.h"

class FloraGroup : public TemplateVariable<'FGRP'> {
	Vector<FloraFamily*> data;
public:

	~FloraGroup();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0008'>);
};
