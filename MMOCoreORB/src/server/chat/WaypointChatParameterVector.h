/*
 * WaypointChatParameterVector.h
 *
 *  Created on: Nov 12, 2010
 *      Author: oru
 */

#pragma once

#include "WaypointChatParameter.h"

namespace server {
namespace chat {

class WaypointChatParameterVector : public Vector<WaypointChatParameter> {

};
} // namespace chat
} // namespace server

using namespace server::chat;
