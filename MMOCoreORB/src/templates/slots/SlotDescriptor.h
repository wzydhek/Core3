/*
 * SlotDescriptor.h
 *
 *  Created on: May 25, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

namespace templates {
namespace slots {

class SlotDescriptor : public IffTemplate {
	Vector<String> slots;

public:
	SlotDescriptor();

	void readObject(IffStream* iffStream);

	void clone(Vector<String>& copyVec) const;

	const Vector<String>* getSlots() const;
};

} // namespace slots
} // namespace templates

using namespace templates::slots;
