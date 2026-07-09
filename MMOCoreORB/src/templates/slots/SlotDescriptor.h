/*
 * SlotDescriptor.h
 *
 *  Created on: May 25, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

class SlotDescriptor : public IffTemplate {
	Vector<String> slots;

public:
	SlotDescriptor();

	void readObject(IffStream* iffStream);

	void clone(Vector<String>& copyVec) const;

	const Vector<String>* getSlots() const;
};
