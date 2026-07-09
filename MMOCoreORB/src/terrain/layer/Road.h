/*
 * Road.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../TemplateVariable.h"
#include "Segment.h"

class Road : public TemplateVariable<'ROAD'> {
	Vector<Segment*> sgmts;

public:
	Road();

	~Road();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);
};
