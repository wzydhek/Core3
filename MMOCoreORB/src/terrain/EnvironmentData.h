/*
 * EnvironmentData.h
 *
 *  Created on: 01/02/2010
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"

namespace terrain {

class EnvironmentData : public TemplateVariable<'EFAM'> {
	int environmentId;
	String environmentName;

	byte var3;
	byte var4;
	byte var5;
	float var6;
public:

	EnvironmentData();

	void parseFromIffStream(engine::util::IffStream* iffStream);

};

} // namespace terrain

using namespace terrain;