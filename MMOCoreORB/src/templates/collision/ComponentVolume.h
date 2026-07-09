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
	bool isComponentVolume();

	ComponentVolume();

	virtual void read(IffStream *iff);
};
