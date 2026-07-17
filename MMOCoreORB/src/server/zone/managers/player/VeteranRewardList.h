/*
 * VeteranRewardList.h
 *
 *  Created on: 5/22/2014
 *      Author: Klivian
 */

#pragma once

#include "VeteranReward.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class VeteranRewardList : public Vector<VeteranReward> {

public:

	VeteranRewardList();

};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;
