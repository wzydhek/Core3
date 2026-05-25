/*
 * GroupList.h
 *
 *  Created on: 29/12/2009
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/scene/variables/DeltaVector.h"
#include "GroupMember.h"

class GroupList : public DeltaVector<GroupMember> {
};
