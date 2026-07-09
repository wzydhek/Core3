/*
 * ActiveAreaOctree.h
 *
 * Created on: 01/03/2024
 * Author: Hakry
*/

#pragma once

#include "system/lang.h"
#include "engine/log/Logger.h"
#include "server/zone/objects/area/ActiveArea.h"
#include "system/util/Vector.h"
#include "system/lang/ref/UniqueReference.h"

// #define AREA_TREE_SIMPLE
// #define DEBUG_AA_OCTREE

namespace server {
namespace zone {

class ActiveAreaOctreeNode : public Logger {
protected:
	SortedVector<Reference<ActiveArea*>> areas;

	UniqueReference<ActiveAreaOctreeNode*> nwNode{};
	UniqueReference<ActiveAreaOctreeNode*> neNode{};
	UniqueReference<ActiveAreaOctreeNode*> swNode{};
	UniqueReference<ActiveAreaOctreeNode*> seNode{};

	UniqueReference<ActiveAreaOctreeNode*> nwNode2{};
	UniqueReference<ActiveAreaOctreeNode*> neNode2{};
	UniqueReference<ActiveAreaOctreeNode*> swNode2{};
	UniqueReference<ActiveAreaOctreeNode*> seNode2{};

	float minX = 0, minZ = 0, minY = 0;
	float maxX = 0, maxZ = 0, maxY = 0;

	const ActiveAreaOctreeNode* parentNode;

	float dividerX = 0, dividerZ = 0, dividerY = 0;

public:
	ActiveAreaOctreeNode(float minx, float minz, float miny, float maxx, float maxz, float maxy, const ActiveAreaOctreeNode* parent);

	bool isEmpty() const;

	void insertArea(ActiveArea* area);

	void dropArea(ActiveArea* area);

	bool testInside(float x, float z, float y) const;

	bool testAreaInside(float x, float z, float y, float radius) const;

	bool testAreaInsideCuboid(ActiveArea* area) const;

	bool hasSubNodes() const;

	bool testInSWArea(float x, float z, float y, float radius) const;

	bool testInSEArea(float x, float z, float y, float radius) const;

	bool testInNWArea(float x, float z, float y, float radius) const;

	bool testInNEArea(float x, float z, float y, float radius) const;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool testInSWArea2(float x, float z, float y, float radius) const;

	bool testInSEArea2(float x, float z, float y, float radius) const;

	bool testInNWArea2(float x, float z, float y, float radius) const;

	bool testInNEArea2(float x, float z, float y, float radius) const;

	friend class ActiveAreaOctree;
};

class ActiveAreaOctree : public Object, public Logger {
#ifdef AREA_TREE_SIMPLE
	SortedVector<Reference<ActiveArea*>> areas;
#else
	UniqueReference<ActiveAreaOctreeNode*> root{};
#endif

public:
	ActiveAreaOctree(float minx, float minz, float miny, float maxx, float maxz, float maxy);

	template <typename AreaType>
	void getActiveAreas(float x, float z, float y, ArrayList<AreaType>& areas) const {
#ifndef AREA_TREE_SIMPLE
		getActiveAreas(root.get(), x, z, y, areas);
#else
		for (const auto& area : areas) {
			if (area->containsPoint(x, z, y)) {
				areas.emplace(area);
			}
		}
#endif
	}

	void insert(Reference<ActiveArea*> area);

	void remove(Reference<ActiveArea*> area);

protected:
#ifndef AREA_TREE_SIMPLE
	void insert(ActiveAreaOctreeNode& node, ActiveArea* area);
	void removeActiveArea(ActiveAreaOctreeNode& node, ActiveArea* area);

	template <typename AreaType>
	void getActiveAreas(ActiveAreaOctreeNode* node, float x, float z, float y, ArrayList<AreaType>& areas) const {
		if (node == nullptr) {
			return;
		}

#ifdef DEBUG_AA_OCTREE
		info(true) << "getActiveAreas - Loc: X = " << x << ", Z = " << z << ", Y = " << y << " Area Size: " << node->areas.size();
#endif

		for (const auto& areaEntry : node->areas) {
			if (areaEntry->containsPoint(x, z, y)) {
				areas.emplace(areaEntry);
			}
		}

		const auto& nodeSW = node->swNode;
		const auto& nodeSE = node->seNode;
		const auto& nodeNW = node->nwNode;
		const auto& nodeNE = node->neNode;

		const auto& nodeSW2 = node->swNode2;
		const auto& nodeSE2 = node->seNode2;
		const auto& nodeNW2 = node->nwNode2;
		const auto& nodeNE2 = node->neNode2;

		if (nodeSW != nullptr && nodeSW->testInside(x, z, y)) {
			getActiveAreas(nodeSW.get(), x, z, y, areas);
		} else if (nodeSE != nullptr && nodeSE->testInside(x, z, y)) {
			getActiveAreas(nodeSE.get(), x, z, y, areas);
		} else if (nodeNW != nullptr && nodeNW->testInside(x, z, y)) {
			getActiveAreas(nodeNW.get(), x, z, y, areas);
		} else if (nodeNE != nullptr && nodeNE->testInside(x, z, y)) {
			getActiveAreas(nodeNE.get(), x, z, y, areas);
		} else if (nodeSW2 != nullptr && nodeSW2->testInside(x, z, y)) {
			getActiveAreas(nodeSW2.get(), x, z, y, areas);
		} else if (nodeSE2 != nullptr && nodeSE2->testInside(x, z, y)) {
			getActiveAreas(nodeSE2.get(), x, z, y, areas);
		} else if (nodeNW2 != nullptr && nodeNW2->testInside(x, z, y)) {
			getActiveAreas(nodeNW2.get(), x, z, y, areas);
		} else if (nodeNE2 != nullptr && nodeNE2->testInside(x, z, y)) {
			getActiveAreas(nodeNE2.get(), x, z, y, areas);
		}
	}
#endif
};

} // namespace zone
} // namespace server
