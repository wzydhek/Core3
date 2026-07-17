/*
 * CreatureTemplateReference.h
 *
 *  Created on: 29/04/2012
 *      Author: victor
 */

#pragma once

#include "engine/util/json_utils.h"
#include "server/zone/objects/creature/ai/CreatureTemplate.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace ai {
namespace variables {

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

} // namespace variables
} // namespace ai
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::ai::variables;
