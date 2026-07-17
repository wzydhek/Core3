/*
 * WeaponObjectMEssage6.h
 *
 *  Created on: 01/05/2012
 *      Author: victor
 */

#pragma once

#include "TangibleObjectMessage6.h"

namespace server {
namespace zone {
namespace packets {
namespace tangible {

class WeaponObjectMessage6 : public TangibleObjectMessage6 {
public:
	WeaponObjectMessage6(TangibleObject* tano);

};

} // namespace tangible
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::tangible;
