/*
 * ArrangementDescriptor.h
 *
 *  Created on: May 25, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

class ArrangementDescriptor : public IffTemplate {
	Vector< Vector<String> > arrangementSlots;

public:
	ArrangementDescriptor();

	void readObject(IffStream* iffStream);

	void clone(Vector<Vector<String>>& copyVec) const;

	const Vector<Vector<String>>& getArrangementSlots() const;
};
