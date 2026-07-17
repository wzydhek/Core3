/*
 * ArrangementDescriptor.h
 *
 *  Created on: May 25, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

namespace templates {
namespace slots {

class ArrangementDescriptor : public IffTemplate {
	Vector< Vector<String> > arrangementSlots;

public:
	ArrangementDescriptor();

	void readObject(IffStream* iffStream);

	void clone(Vector<Vector<String>>& copyVec) const;

	const Vector<Vector<String>>& getArrangementSlots() const;
};

} // namespace slots
} // namespace templates

using namespace templates::slots;
