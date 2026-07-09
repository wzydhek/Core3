/*
 * SharedJediManagerTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedUniverseObjectTemplate.h"

class SharedJediManagerTemplate : public SharedUniverseObjectTemplate {

public:
	SharedJediManagerTemplate();

	~SharedJediManagerTemplate();

	void readObject(IffStream* iffStream);

};
