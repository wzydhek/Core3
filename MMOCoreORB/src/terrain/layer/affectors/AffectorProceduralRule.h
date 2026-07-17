/*
 * AffectorProceduralRule.h
 *
 *  Created on: 21/12/2010
 *      Author: victor
 */

#pragma once

namespace terrain {

class TerrainGenerator;

} // namespace terrain

using namespace terrain;

namespace terrain {
namespace layer {
namespace affectors {

class AffectorProceduralRule {
protected:
	int affectorType;

public:
	AffectorProceduralRule();

	const static int HEIGHTTYPE = 0x100;
	const static int HEIGHTFRACTAL = 0x101;
	const static int HEIGHTTERRACE = 0x102;
	const static int HEIGHTCONSTANT = 0x103;
	const static int HEIGHTROAD = 0x104;
	const static int ENVIRONMENT = 0x200;

	virtual ~AffectorProceduralRule() {

	}

	virtual void process(float x, float y, float transformValue, float& baseValue, TerrainGenerator* terrainGenerator) {
	}

	bool isHeightTypeAffector() const;

	bool isEnvoronmentTypeAffector() const;

	int getAffectorType() const;

	virtual bool isEnabled();

};

} // namespace affectors
} // namespace layer
} // namespace terrain

using namespace terrain::layer::affectors;
