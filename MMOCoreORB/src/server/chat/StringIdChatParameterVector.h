/*
 * StringIdChatParameterVector.h
 *
 *  Created on: Nov 12, 2010
 *      Author: oru
 */

#pragma once

#include "StringIdChatParameter.h"

namespace server {
namespace chat {

class StringIdChatParameterVector : public Vector<StringIdChatParameter> {

};

} // namespace chat
} // namespace server

using namespace server::chat;
