/*
 * VuidString.h
 *
 *  Created on: Jun 11, 2012
 *      Author: kyle
 */

#pragma once

#include "engine/engine.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace auction {

class VuidString : public String {
public:

	VuidString();

	~VuidString();

	VuidString(const String& val);

	VuidString(const char* str);

	VuidString(const VuidString& val);

	int compareTo(const VuidString& str) const;
};

} // namespace auction
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::auction;
