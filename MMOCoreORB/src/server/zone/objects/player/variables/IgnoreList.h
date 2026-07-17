/*
 * IgnoreList.h
 *
 *  Created on: 05/02/2010
 *      Author: victor
 */

#pragma once

#include "PlayerList.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace variables {

class IgnoreList : public PlayerList<8> {

};

} // namespace variables
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::variables;
