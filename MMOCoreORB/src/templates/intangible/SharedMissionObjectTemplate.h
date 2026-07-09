/*
 * SharedMissionObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

class SharedMissionObjectTemplate : public SharedIntangibleObjectTemplate {

public:
	SharedMissionObjectTemplate();

	~SharedMissionObjectTemplate();

	void readObject(IffStream* iffStream);

};
