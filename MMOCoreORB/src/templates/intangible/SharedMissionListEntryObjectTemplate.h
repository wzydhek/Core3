/*
 * SharedMissionListEntryObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

class SharedMissionListEntryObjectTemplate : public SharedIntangibleObjectTemplate {

public:
	SharedMissionListEntryObjectTemplate();

	~SharedMissionListEntryObjectTemplate();

	void readObject(IffStream* iffStream);

};
