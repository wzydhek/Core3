/*
 * SharedManufactureSchematicObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

class SharedManufactureSchematicObjectTemplate : public SharedIntangibleObjectTemplate {

public:
	SharedManufactureSchematicObjectTemplate();

	~SharedManufactureSchematicObjectTemplate();

	void readObject(IffStream* iffStream);
};
