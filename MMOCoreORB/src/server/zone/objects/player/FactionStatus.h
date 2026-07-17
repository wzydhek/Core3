/*
 * FactionStatus.h
 *
 *  Created on: 13/01/2012
 *      Author: victor
 */

#pragma once

namespace server {
namespace zone {
namespace objects {
namespace player {

class FactionStatus {
public:
	const static int OVERT = 2;
	const static int COVERT = 1;
	const static int ONLEAVE = 0;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;
