/*
 * PortalLayout.h
 *
 *  Created on: 02/12/2010
 *      Author: victor
 */

#pragma once

#include "templates/IffTemplate.h"
#include "templates/appearance/CellProperty.h"
#include "templates/appearance/MeshData.h"
#include "templates/appearance/PathNode.h"
#include "templates/appearance/FloorMesh.h"
#include "templates/appearance/AppearanceTemplate.h"
#include "templates/appearance/PathGraph.h"

namespace templates {
namespace appearance {

class PortalGeometry : public Object {
	Reference<MeshData*> geometry;
	AABB boundingBox;
public:
	PortalGeometry();

	MeshData* getGeometry();

	const MeshData* getGeometry() const;

	const AABB& getBoundingBox() const;

	void setBoundingBox(const AABB& aabb);
};

class PortalLayout : public IffTemplate, public Logger {
	PathGraph* pathGraph;
	Vector<Reference<PortalGeometry*> > portalGeometry;
	Vector<Reference<CellProperty*> > cellProperties;
public:
	PortalLayout();
	~PortalLayout();

	const PathGraph* getPathGraph() const;

	void readPortalGeometry0003(IffStream *iff, int numPortals);
	void readPortalGeometry0004(IffStream *iff, int numPortals);

	void readObject(IffStream* templateData);

	void parse(IffStream* iffStream);

	void parseCELSForm(IffStream* iffStream, int numCells);

	void connectFloorMeshGraphs();

	int getFloorMeshID(int globalNodeID, int floorMeshToExclude) const;

	Vector<const PathNode*>* getPath(const PathNode* node1, const PathNode* node2) const;

	int getCellID(const String& cellName) const;

	int getCellTotalNumber() const;

	int getFloorMeshNumber() const;

	const FloorMesh* getFloorMesh(int cellIndex) const;

	FloorMesh* getFloorMesh(int cellIndex);

	const AppearanceTemplate* getAppearanceTemplate(int cellIndex) const;

	const Vector<Reference<CellProperty*>>& getCellProperties() const;

	const CellProperty* getCellProperty(int cellIndex) const;

	int getAppearanceTemplatesSize() const;

	const MeshData* getPortalGeometry(int idx) const;

	const AABB& getPortalBounds(int idx) const;

	static uint32 loadCRC(IffStream* iffStream);
};

} // namespace appearance
} // namespace templates

using namespace templates::appearance;
