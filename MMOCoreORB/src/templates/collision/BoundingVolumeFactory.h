/*
 * BoundingVolumeFactory.h
 *
 *  Created on: 3/20/16
 *      Author: gslomin
 */

#pragma once

#include "engine/util/iffstream/IffStream.h"

#include "BaseBoundingVolume.h"

namespace templates {
namespace collision {

class BoundingVolumeFactory {
public:
	BoundingVolumeFactory() { }
	static BaseBoundingVolume* getVolume(IffStream *iff);
};

} // namespace collision
} // namespace templates

using namespace templates::collision;
