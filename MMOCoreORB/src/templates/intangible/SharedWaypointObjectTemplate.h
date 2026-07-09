/*
 * SharedWaypointObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

class SharedWaypointObjectTemplate : public SharedIntangibleObjectTemplate {

public:
	SharedWaypointObjectTemplate();

	~SharedWaypointObjectTemplate();

	void readObject(IffStream* iffStream);

};
