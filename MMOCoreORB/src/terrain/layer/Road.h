/*
 * Road.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../TemplateVariable.h"
#include "Segment.h"

namespace terrain {
namespace layer {

class Road : public TemplateVariable<'ROAD'> {
	Vector<Segment*> sgmts;

public:
	Road();

	~Road();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);
};

} // namespace layer
} // namespace terrain

using namespace terrain::layer;
