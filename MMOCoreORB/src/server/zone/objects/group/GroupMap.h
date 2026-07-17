/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "system/lang.h"
#include "system/util/HashTable.h"
#include "server/zone/objects/group/GroupObject.h"

namespace server {
namespace zone {
namespace objects {
namespace group {

class GroupMap : public HashTable<uint64, GroupObject*> {
	int hash(uint64 const& key) const override;

public:
	GroupMap(int initsize);

};

} // namespace group
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::group;
