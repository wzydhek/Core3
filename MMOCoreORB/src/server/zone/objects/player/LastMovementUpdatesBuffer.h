/*
 * LastMovementUpdatesBuffer.h
 *
 *  Created on: 24/11/2010
 *      Author: victor
 */

#pragma once

#include "server/zone//packets/MessageCallback.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class LastMovementUpdatesBuffer : public Vector<Reference<MessageCallback*> > {

};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;
