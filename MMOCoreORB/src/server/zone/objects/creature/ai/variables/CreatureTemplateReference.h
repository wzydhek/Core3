/*
 * CreatureTemplateReference.h
 *
 *  Created on: 29/04/2012
 *      Author: victor
 */

#pragma once

#include "engine/util/json_utils.h"
#include "server/zone/objects/creature/ai/CreatureTemplate.h"

class CreatureTemplateReference : public Reference<CreatureTemplate*> {
#ifdef ODB_SERIALIZATION
	String templateString;
#endif
public:
	bool toBinaryStream(ObjectOutputStream* stream);
	bool parseFromBinaryStream(ObjectInputStream* stream);
	CreatureTemplate* operator=(CreatureTemplate* obj);

	friend void to_json(nlohmann::json& j, const CreatureTemplateReference& r);
};
