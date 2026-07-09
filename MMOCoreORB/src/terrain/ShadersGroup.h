/*
 * SurfaceGroup.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "ShaderFamily.h"

class ShadersGroup : public TemplateVariable<'SGRP'> {
	Vector<ShaderFamily*> data;

public:

	ShadersGroup();

	~ShadersGroup();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0006'>);

};
