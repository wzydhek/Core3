/*
 * CellProperty.h
 *
 *  Created on: Apr 19, 2015
 *      Author: TheAnswer
 */

#pragma once

#include "engine/engine.h"
#include "templates/IffTemplate.h"
#include "templates/collision/BaseBoundingVolume.h"
#include "templates/appearance/FloorMesh.h"
#include "templates/appearance/AppearanceTemplate.h"

class CellPortal : public Object {
	bool solid;
	int geometryIndex;
	bool winding;
	int targetCell;
	String doorName;
	bool transformFlag;
	Matrix4 doorTransform;
public:

	void readObject(IffStream *iff);

	bool isSolid() const;

	int getGeometryIndex() const;

	bool isWindingCCW() const;

	int getTargetCellIndex() const;

	const String& getDoorTemplate() const;

	bool hasDoorTemplate() const;

	bool hasDoorTransform() const;

	const Matrix4& getDoorTransform() const;

};

class CellProperty : public IffTemplate, public Logger {
protected:
	String name;
	int numberOfPortals;
	bool worldPortal = false;
	FloorMesh* floorMesh;
	AppearanceTemplate* appearanceTemplate;
	int cellID;
	Reference<BaseBoundingVolume*> boundingVolume;
	Vector<Reference<CellPortal*> > portals;
	SortedVector<int> connectedCells;

public:
	CellProperty();
	CellProperty(int cellID);
	CellProperty(const CellProperty& c);

	CellProperty& operator=(const CellProperty& c);

	void readObject(IffStream* iffStream);

	AppearanceTemplate* getAppearanceTemplate();

	void addConnectedCell(int cellID);

	const SortedVector<int>& getConnectedCells() const;

	bool hasConnectedCell(int cellID) const;

	const FloorMesh* getFloorMesh() const;

	FloorMesh* getFloorMesh();

	const String& getName() const;

	int getCellID() const;

	int getNumberOfPortals() const;

	bool hasWorldPortal() const;

	const CellPortal* getPortal(int idx) const;

	void loadVersion4(IffStream* iffStream);
	void loadVersion5(IffStream* iffStream);
};
