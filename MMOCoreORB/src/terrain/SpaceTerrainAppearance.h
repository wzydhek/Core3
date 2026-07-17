/*
 * SpaceTerrainAppearance.h
 *
 *  Created on: 17/10/2013
 *      Author: victor
 */

#pragma once

#include "TemplateVariable.h"
#include "TerrainAppearance.h"

namespace terrain {

class SpaceTerrainAppearance : public TemplateVariable<'STAT'>, public Logger, public TerrainAppearance {
protected:
	void parseSKYB(engine::util::IffStream* iffStream);
	void parseSTAR(engine::util::IffStream* iffStream);
	void parsePLAN(engine::util::IffStream* iffStream);
	void parseFOG(engine::util::IffStream* iffStream);
	void parsePARA(engine::util::IffStream* iffStream);
	void parseENVI(engine::util::IffStream* iffStream);
	void parseAMBI(engine::util::IffStream* iffStream);
	void parseDIST(engine::util::IffStream* iffStream);
	void parseDUST(engine::util::IffStream* iffStream);
	void parseCLEA(engine::util::IffStream* iffStream);
	void parseCELE(engine::util::IffStream* iffStream);

public:
	SpaceTerrainAppearance();
	bool load(engine::util::IffStream* iffStream) override;

	void parseFromIffStream(engine::util::IffStream* iffStream) override;
	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0000'>);

	float getSize() const override;

};

} // namespace terrain

using namespace terrain;
