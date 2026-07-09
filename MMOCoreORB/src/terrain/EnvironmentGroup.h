/*
 * EnvironmentGroup.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "EnvironmentData.h"

class EnvironmentGroup : public TemplateVariable<'EGRP'> {
	Vector<EnvironmentData*> data;

public:

	EnvironmentGroup();

	~EnvironmentGroup();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0002'>);
};
