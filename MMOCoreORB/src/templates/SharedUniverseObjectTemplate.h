/*
 * SharedUniverseObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedObjectTemplate.h"

class SharedUniverseObjectTemplate : public SharedObjectTemplate {
protected:


public:
	SharedUniverseObjectTemplate();

	~SharedUniverseObjectTemplate();

	void readObject(IffStream* iffStream);

};
