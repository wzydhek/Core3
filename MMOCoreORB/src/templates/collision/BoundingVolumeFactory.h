/*
 * BoundingVolumeFactory.h
 *
 *  Created on: 3/20/16
 *      Author: gslomin
 */

#pragma once

#include "engine/util/iffstream/IffStream.h"

#include "BaseBoundingVolume.h"

class BoundingVolumeFactory {
public:
	BoundingVolumeFactory() { }
	static BaseBoundingVolume* getVolume(IffStream *iff);
};
