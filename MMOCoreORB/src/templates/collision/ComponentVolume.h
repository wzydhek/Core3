/*
 * ComponentVolume.h
 *
 *  Created on: 03/20/2016
 *      Author: gslomin
 */

#pragma once

#include "CompositeVolume.h"

namespace templates {
namespace collision {

class ComponentVolume : public CompositeVolume {
public:
	bool isComponentVolume();

	ComponentVolume();

	virtual void read(IffStream *iff);
};

} // namespace collision
} // namespace templates

using namespace templates::collision;
