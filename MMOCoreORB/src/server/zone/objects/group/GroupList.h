/*
 * GroupList.h
 *
 *  Created on: 29/12/2009
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/scene/variables/DeltaVector.h"
#include "GroupMember.h"

namespace server {
namespace zone {
namespace objects {
namespace group {

class GroupList : public DeltaVector<GroupMember> {
};

} // namespace group
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::group;
