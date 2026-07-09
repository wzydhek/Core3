/*
 * SharedMissionDataObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

class SharedMissionDataObjectTemplate : public SharedIntangibleObjectTemplate {

public:
	SharedMissionDataObjectTemplate();

	~SharedMissionDataObjectTemplate();

	void readObject(IffStream* iffStream);


};
