/*
 * InformationHeader.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../TemplateVariable.h"

namespace terrain {
namespace layer {

class InformationHeader : public TemplateVariable<'IHDR'> {
	int var1;
	String description;

public:
	InformationHeader();

	void parseFromIffStream(engine::util::IffStream* iffStream);

	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0001'>);

	bool isEnabled() const;

	String& getDescription();

	const String& getDescription() const;
};

} // namespace layer
} // namespace terrain

using namespace terrain::layer;
