/*
 * SchematicFragmentTemplate.h
 *
 *  Created on: 02/06/2025
 *      Author: Halyn
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class SchematicFragmentTemplate : public SharedTangibleObjectTemplate {
protected:
	int totalFragments;
	unsigned int fragmentBitmask;
	uint32 targetSchematic;


public:
	SchematicFragmentTemplate();

	~SchematicFragmentTemplate();

	void readObject(LuaObject* templateData);

	int getTotalFragments();

	unsigned int getfragmentBitmask();

	bool isSchematicFragmentTemplate();

	uint32 getTargetSchematic();
};
