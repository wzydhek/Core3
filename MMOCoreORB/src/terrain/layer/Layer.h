/*
 * Layer.h
 *
 *  Created on: 31/01/2010
 *      Author: victor
 */

#pragma once

#include "../TemplateVariable.h"
#include "InformationHeader.h"

/*class Boundary;
class AffectorProceduralRule;
class FilterProceduralRule;*/

#include "boundaries/Boundary.h"
#include "affectors/AffectorProceduralRule.h"
#include "filters/FilterProceduralRule.h"

class Layer : public TemplateVariable<'LAYR'> {
	InformationHeader infoHeader;

	Vector<Layer*> children;
	//Vector<TerrainRule*> rules;

	Vector<Boundary*> boundaries;
	Vector<AffectorProceduralRule*> affectors;
	Vector<FilterProceduralRule*> filters;

	//Vector<AffectorProceduralRule*> heightAffectors;
	//Vector<AffectorProceduralRule*> environmentAffectors;

	Layer* parent;

	int boundariesFlag;
	int filterFlag;

public:
	Layer(Layer* par = nullptr);

	~Layer();

	void parseFromIffStream(engine::util::IffStream* iffStream);
	void parseFromIffStream(engine::util::IffStream* iffStream, Version<'0003'>);

	IffTemplateVariable* parseAffector(IffStream* iffStream);
	Boundary* parseBoundary(IffStream* iffStream);
	FilterProceduralRule* parseFilter(IffStream* iffStream);

	Vector<Layer*>* getChildren();

	Vector<Boundary*>* getBoundaries();

	Vector<AffectorProceduralRule*>* getAffectors();

	Vector<FilterProceduralRule*>* getFilters();

	const Vector<Layer*>* getChildren() const;

	const Vector<Boundary*>* getBoundaries() const;

	const Vector<AffectorProceduralRule*>* getAffectors() const;

	const Vector<FilterProceduralRule*>* getFilters() const;

	inline Layer* getParent();

	const Layer* getParent() const;

	bool invertBoundaries() const;

	bool invertFilters() const;

	bool isEnabled() const;

	const String& getDescription() const;
};
