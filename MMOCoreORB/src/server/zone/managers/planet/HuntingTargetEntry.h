/*
 * HuntingTargetEntry.h
 *
 *  Created on: Aug 27, 2010
 *      Author: da
 */

#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace planet {

class HuntingTargetEntry : public Object {
private:
	String templatePrimary;
	String templateSecondary;

public:
	HuntingTargetEntry();

	HuntingTargetEntry(const String& temp1, const String& temp2);

	String getPrimary();

	String getSecondary();

	int compareTo(const HuntingTargetEntry& entry) const;
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;
