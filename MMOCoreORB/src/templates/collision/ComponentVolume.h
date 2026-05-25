/*
 * ComponentVolume.h
 *
 *  Created on: 03/20/2016
 *      Author: gslomin
 */

#pragma once

#include "CompositeVolume.h"

class ComponentVolume : public CompositeVolume {
public:
	bool isComponentVolume() { return true; }
	ComponentVolume() { }
	virtual void read(IffStream *iff);
};
