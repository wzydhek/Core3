/*
 * GroupMember.h
 *
 *  Created on: 29/12/2009
 *      Author: victor
 */

#pragma once

#include "engine/util/json_utils.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
class CreatureObject;
}
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

class GroupMember : public Variable {
	ManagedReference<CreatureObject*> creature;

public:
	GroupMember();

	GroupMember(const GroupMember& obj);

	GroupMember(CreatureObject* obj);

	GroupMember& operator=(const GroupMember& obj);

	bool operator==(const GroupMember& member) const;

	bool operator==(CreatureObject* member) const;

	void operator=(CreatureObject* obj);

	Reference<CreatureObject*> operator->() const;

	Reference<CreatureObject*> get();

	operator Reference<CreatureObject*>() const {
		return creature.get();
	}

	bool toString(String& str);

	bool parseFromString(const String& str, int version = 0);

	friend void to_json(nlohmann::json& j, const GroupMember& m);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);
};
