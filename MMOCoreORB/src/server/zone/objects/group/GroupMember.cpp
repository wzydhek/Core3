/*
* GroupMember.cpp
*/

#include "server/zone/objects/creature/CreatureObject.h"

#include "GroupMember.h"

GroupMember::GroupMember() {
	creature = nullptr;
}

GroupMember::GroupMember(const GroupMember& obj) : Variable() {
	creature = obj.creature;
}

GroupMember::GroupMember(CreatureObject* obj) {
	creature = obj;
}

GroupMember& GroupMember::operator=(const GroupMember& obj) {
	if (this == &obj) {
		return *this;
	}

	creature = obj.creature;

	return *this;
}

bool GroupMember::operator==(const GroupMember& member) const {
	return creature.get() == member.creature.get();
}

bool GroupMember::operator==(CreatureObject* member) const {
	return creature.get() == member;
}

void GroupMember::operator=(CreatureObject* obj) {
	creature = obj;
}

Reference<CreatureObject*> GroupMember::operator->() const {
	return creature.get();
}

Reference<CreatureObject*> GroupMember::get() {
	return creature.get();
}

bool GroupMember::toString(String& str) {
	return creature.toString(str);
}

bool GroupMember::parseFromString(const String& str, int version) {
	return creature.parseFromString(str, version);
}

void server::zone::objects::group::to_json(nlohmann::json& j, const GroupMember& m) {
	String name;

	j["creature"] = m.creature;

	if (m.creature != nullptr) {
		name = m.creature->getCustomObjectName().toString();
	}

	j["name"] = name;
}

bool GroupMember::toBinaryStream(ObjectOutputStream* stream) {
	String name;

	creature.toBinaryStream(stream);

	if (creature != nullptr) {
		name = creature->getCustomObjectName().toString();
	}

	name.toBinaryStream(stream);

	return true;
}

bool GroupMember::parseFromBinaryStream(ObjectInputStream* stream) {
	creature.parseFromBinaryStream(stream);

	if (creature == nullptr)
		return false;

	String name;

	name.parseFromBinaryStream(stream);

	return true;
}