/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "server/zone/ActiveAreaOctree.h"
#include "server/zone/objects/area/areashapes/CuboidAreaShape.h"
#include "server/zone/objects/area/areashapes/SphereAreaShape.h"

using namespace server::zone;

ActiveAreaOctreeNode::ActiveAreaOctreeNode(float minx, float minz, float miny, float maxx, float maxz, float maxy, const ActiveAreaOctreeNode* parent) : minX(minx), minZ(minz), minY(miny), maxX(maxx), maxZ(maxz), maxY(maxy), parentNode(parent) {
	dividerX = (minX + maxX) / 2;
	dividerZ = (minZ + maxZ) / 2;
	dividerY = (minY + maxY) / 2;

	areas.setNoDuplicateInsertPlan();

	setLoggingName("ActiveAreaOctreeNode");
}

bool ActiveAreaOctreeNode::isEmpty() const {
	return areas.isEmpty();
}

void ActiveAreaOctreeNode::insertArea(ActiveArea* area) {
	areas.put(area);
}

void ActiveAreaOctreeNode::dropArea(ActiveArea* area) {
	areas.drop(area);
}

bool ActiveAreaOctreeNode::testInside(float x, float z, float y) const {
	return x >= minX && x < maxX && y >= minY && y < maxY && z >= minZ && z < maxZ;
}

bool ActiveAreaOctreeNode::testAreaInside(float x, float z, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;
	float zDelta1 = z - radius;
	float zDelta2 = z + radius;

#ifdef DEBUG_AA_OCTREE
	info(true) << "testAreaInside --- Radius: " << radius << " xDelta1 = " << xDelta1 << " xDelta2 = " << xDelta2 << " yDelta1 = " << yDelta1 << " yDelta2 = " << yDelta2 << " zDelta1 = " << zDelta1 << " zDelta2 = " << zDelta2;
	info(true) << "minX = " << minX << " maxX = " << maxX << " minZ = " << minZ << " maxZ = " << maxZ << " minY = " << minY << " maxY = " << maxY;
#endif

	bool runTest = ((xDelta1 > minX && xDelta2 < maxX) && (yDelta1 > minY && yDelta2 < maxY) && (zDelta1 > minZ && zDelta2 < maxZ));

	return runTest;
}

bool ActiveAreaOctreeNode::testAreaInsideCuboid(ActiveArea* area) const {
	if (area == nullptr)
		return false;

	Vector3 centerPos = area->getAreaCenter();
	Vector3 cuboidDimensions = area->getCuboidDimensions();

	float length = cuboidDimensions[0];
	float width = cuboidDimensions[1];
	float height = cuboidDimensions[2];

#ifdef DEBUG_AA_OCTREE
	info(true) << "testAreaInsideCuboid -- called for " << area->getAreaName() << " Location: " << centerPos.toString() << " Length: " << length << " Width: " << width << " Height: " << height;
#endif

	float areaMinX, areaMinY, areaMinZ, areaMaxX, areaMaxY, areaMaxZ;

	areaMinX = centerPos.getX() - (width / 2);
	areaMaxX = centerPos.getX() + (width / 2);
	areaMinY = centerPos.getY() - (length / 2);
	areaMaxY = centerPos.getY() + (length / 2);
	areaMinZ = centerPos.getZ() - (height / 2);
	areaMaxZ = centerPos.getZ() + (height / 2);

	bool runTestX = (areaMinX >= minX && areaMaxX < maxX);
	bool runTestY = (areaMinY >= minY && areaMaxY < maxY);
	bool runTestZ = (areaMinZ >= minZ && areaMaxZ < maxZ);

	return runTestX && runTestY && runTestZ;
}

bool ActiveAreaOctreeNode::hasSubNodes() const {
	return nwNode != nullptr || neNode != nullptr || swNode != nullptr || seNode != nullptr || nwNode2 != nullptr || neNode2 != nullptr || swNode2 != nullptr || seNode2 != nullptr;
}

bool ActiveAreaOctreeNode::testInSWArea(float x, float z, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;
	float zDelta1 = z - radius;
	float zDelta2 = z + radius;

#ifdef DEBUG_AA_OCTREE
	info(true) << "testInSWArea --- Radius: " << radius << " xDelta1 = " << xDelta1 << " xDelta2 = " << xDelta2 << " yDelta1 = " << yDelta1 << " yDelta2 = " << yDelta2 << " zDelta1 = " << zDelta1 << " zDelta2 = " << zDelta2;
	info(true) << "minX = " << minX << " dividerX = " << dividerX << " minZ = " << minZ << " dividerZ = " << dividerZ << " minY = " << minY << " dividerY = " << dividerY;
#endif

	return (xDelta1 > minX && xDelta2 < dividerX) && (yDelta1 > minY && yDelta2 < dividerY) && (zDelta1 > minZ && zDelta2 < dividerZ);
}

bool ActiveAreaOctreeNode::testInSEArea(float x, float z, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;
	float zDelta1 = z - radius;
	float zDelta2 = z + radius;

#ifdef DEBUG_AA_OCTREE
	info(true) << "testInSEArea --- Radius: " << radius << " xDelta1 = " << xDelta1 << " xDelta2 = " << xDelta2 << " yDelta1 = " << yDelta1 << " yDelta2 = " << yDelta2 << " zDelta1 = " << zDelta1 << " zDelta2 = " << zDelta2;
	info(true) << "dividerX = " << dividerX << " maxX = " << maxX << " minZ = " << minZ << " dividerZ = " << dividerZ << " minY = " << minY << " dividerY = " << dividerY;
#endif

	return (xDelta1 > dividerX && xDelta2 < maxX) && (yDelta1 > minY && yDelta2 < dividerY) && (zDelta1 > minZ && zDelta2 < dividerZ);
}

bool ActiveAreaOctreeNode::testInNWArea(float x, float z, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;
	float zDelta1 = z - radius;
	float zDelta2 = z + radius;

#ifdef DEBUG_AA_OCTREE
	info(true) << "testInNWArea --- Radius: " << radius << " xDelta1 = " << xDelta1 << " xDelta2 = " << xDelta2 << " yDelta1 = " << yDelta1 << " yDelta2 = " << yDelta2 << " zDelta1 = " << zDelta1 << " zDelta2 = " << zDelta2;
	info(true) << "minX = " << minX << " dividerX = " << dividerX << " minZ = " << minZ << " dividerZ = " << dividerZ << " dividerY = " << dividerY << " maxY = " << maxY;
#endif

	return (xDelta1 > minX && xDelta2 < dividerX) && (yDelta1 > dividerY && yDelta2 < maxY) && (zDelta1 > minZ && zDelta2 < dividerZ);
}

bool ActiveAreaOctreeNode::testInNEArea(float x, float z, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;
	float zDelta1 = z - radius;
	float zDelta2 = z + radius;

#ifdef DEBUG_AA_OCTREE
	info(true) << "testInNEArea --- Radius: " << radius << " xDelta1 = " << xDelta1 << " xDelta2 = " << xDelta2 << " yDelta1 = " << yDelta1 << " yDelta2 = " << yDelta2 << " zDelta1 = " << zDelta1 << " zDelta2 = " << zDelta2;
	info(true) << "minX = " << minX << " dividerX = " << dividerX << " minZ = " << minZ << " dividerZ = " << dividerZ << " dividerY = " << dividerY << " maxY = " << maxY;
#endif

	return (xDelta1 > dividerX && xDelta2 < maxX) && (yDelta1 > dividerY && yDelta2 < maxY) && (zDelta1 > minZ && zDelta2 < dividerZ);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ActiveAreaOctreeNode::testInSWArea2(float x, float z, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;
	float zDelta1 = z - radius;
	float zDelta2 = z + radius;

#ifdef DEBUG_AA_OCTREE
	info(true) << "testInSWArea2 --- Radius: " << radius << " xDelta1 = " << xDelta1 << " xDelta2 = " << xDelta2 << " yDelta1 = " << yDelta1 << " yDelta2 = " << yDelta2 << " zDelta1 = " << zDelta1 << " zDelta2 = " << zDelta2;
	info(true) << "minX = " << minX << " dividerX = " << dividerX << " dividerZ = " << dividerZ << " maxZ = " << maxZ << " minY = " << minY << " dividerY = " << dividerY;
#endif

	return (xDelta1 > minX && xDelta2 < dividerX) && (yDelta1 > minY && yDelta2 < dividerY) && (zDelta1 > dividerZ && zDelta2 < maxZ);
}

bool ActiveAreaOctreeNode::testInSEArea2(float x, float z, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;
	float zDelta1 = z - radius;
	float zDelta2 = z + radius;

#ifdef DEBUG_AA_OCTREE
	info(true) << "testInSEArea2 --- Radius: " << radius << " xDelta1 = " << xDelta1 << " xDelta2 = " << xDelta2 << " yDelta1 = " << yDelta1 << " yDelta2 = " << yDelta2 << " zDelta1 = " << zDelta1 << " zDelta2 = " << zDelta2;
	info(true) << "dividerX = " << dividerX << " maxX = " << maxX << " minZ = " << minZ << " maxZ = " << maxZ << " minY = " << minY << " maxY = " << maxY;
#endif

	return (xDelta1 > dividerX && xDelta2 < maxX) && (yDelta1 > minY && yDelta2 < dividerY) && (zDelta1 > dividerZ && zDelta2 < maxZ);
}

bool ActiveAreaOctreeNode::testInNWArea2(float x, float z, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;
	float zDelta1 = z - radius;
	float zDelta2 = z + radius;

#ifdef DEBUG_AA_OCTREE
	info(true) << "testInNWArea2 --- Radius: " << radius << " xDelta1 = " << xDelta1 << " xDelta2 = " << xDelta2 << " yDelta1 = " << yDelta1 << " yDelta2 = " << yDelta2 << " zDelta1 = " << zDelta1 << " zDelta2 = " << zDelta2;
	info(true) << "minX = " << minX << " dividerX = " << dividerX << " dividerZ = " << dividerZ << " maxZ = " << maxZ << " dividerY = " << minY << " maxY = " << maxY;
#endif

	return (xDelta1 > minX && xDelta2 < dividerX) && (yDelta1 > dividerY && yDelta2 < maxY) && (zDelta1 > dividerZ && zDelta2 < maxZ);
}

bool ActiveAreaOctreeNode::testInNEArea2(float x, float z, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;
	float zDelta1 = z - radius;
	float zDelta2 = z + radius;

#ifdef DEBUG_AA_OCTREE
	info(true) << "testInNEArea2 --- Radius: " << radius << " xDelta1 = " << xDelta1 << " xDelta2 = " << xDelta2 << " yDelta1 = " << yDelta1 << " yDelta2 = " << yDelta2 << " zDelta1 = " << zDelta1 << " zDelta2 = " << zDelta2;
	info(true) << "dividerX = " << dividerX << " maxX = " << maxX << " dividerZ = " << dividerZ << " maxZ = " << maxZ << " dividerY = " << dividerY << " maxY = " << maxY;
#endif

	return (xDelta1 > dividerX && xDelta2 < maxX) && (yDelta1 > dividerY && yDelta2 < maxY) && (zDelta1 > dividerZ && zDelta2 < maxZ);
}

ActiveAreaOctree::ActiveAreaOctree(float minx, float minz, float miny, float maxx, float maxz, float maxy) {
#ifndef AREA_TREE_SIMPLE
	root = makeUnique<ActiveAreaOctreeNode>(minx, minz, miny, maxx, maxz, maxy, nullptr);
#else
	areas.setNoDuplicateInsertPlan();
#endif

	setLoggingName("ActiveAreaOctree");
}

void ActiveAreaOctree::insert(Reference<ActiveArea*> area) {
#ifndef AREA_TREE_SIMPLE
	insert(*root, area);
#else
	areas.put(std::move(area));
#endif
}

#ifndef AREA_TREE_SIMPLE


void ActiveAreaOctree::insert(ActiveAreaOctreeNode& node, ActiveArea* area) {
#ifdef DEBUG_AA_OCTREE
	StringBuffer debugMsg;
	debugMsg << "ActiveAreaOctree::insert -- called " << area->getAreaName() << " Center Point = " << area->getAreaCenter().toString() << " Radius = " << area->getRadius() << "\n";
	debugMsg << "Node Info: minX = " << node.minX << " minZ = " << node.minZ << " minY = " << node.minY << " maxX = " << node.maxX << " maxZ = " << node.maxZ << " maxY = " << node.maxY << "\n";
	debugMsg << "DividerX = " << node.dividerX << " dividerZ = " << node.dividerZ << " dividerY = " << node.dividerY << "\n";

	if (area->isCuboidAreaShape()) {
		CuboidAreaShape* cube = cast<CuboidAreaShape*>(area->getAreaShape());

		debugMsg << cube->getDimensionLog();
	}

	info(true) << debugMsg.toString();
#endif

	if (!node.hasSubNodes()) {
#ifdef DEBUG_AA_OCTREE
		info(true) << "insert -- area has no subnodes.";
#endif

		if ((node.maxX - node.minX <= 8) && (node.maxZ - node.minZ <= 8) && (node.maxY - node.minY <= 8)) {
			node.insertArea(area);
			return;
		}
	}

	Vector3 location = area->getAreaCenter();

	const float x = location.getX();
	const float z = location.getZ();
	const float y = location.getY();

	const float radius = area->getRadius();

	bool isCuboid = area->isCuboidAreaShape();

#ifdef DEBUG_AA_OCTREE
	info(true) << "insert -- isCuboid: " << (isCuboid ? "True" : "False") << " Radius: " << radius;
#endif

	if ((isCuboid && node.testAreaInsideCuboid(area)) || node.testAreaInside(x, z, y, radius)) {
		if (node.testInSWArea(x, z, y, radius)) {
			if (node.swNode == nullptr) {
				node.swNode = makeUnique<ActiveAreaOctreeNode>(node.minX, node.minZ, node.minY, node.dividerX, node.dividerZ, node.dividerY, &node);
			}

#ifdef DEBUG_AA_OCTREE
			info(true) << "Inside SW node";
#endif

			insert(*node.swNode, area);
		} else if (node.testInSEArea(x, z, y, radius)) {
			if (node.seNode == nullptr) {
				node.seNode = makeUnique<ActiveAreaOctreeNode>(node.dividerX, node.minZ, node.minY, node.maxX, node.dividerZ, node.dividerY, &node);
			}

#ifdef DEBUG_AA_OCTREE
			info(true) << "Inside SE node";
#endif

			insert(*node.seNode, area);
		} else if (node.testInNWArea(x, z, y, radius)) {
			if (node.nwNode == nullptr) {
				node.nwNode = makeUnique<ActiveAreaOctreeNode>(node.minX, node.minZ, node.dividerY, node.dividerX, node.dividerZ, node.maxY, &node);
			}

#ifdef DEBUG_AA_OCTREE
			info(true) << "Inside NW node";
#endif

			insert(*node.nwNode, area);
		} else if (node.testInNEArea(x, z, y, radius)) {
			if (node.neNode == nullptr) {
				node.neNode = makeUnique<ActiveAreaOctreeNode>(node.dividerX, node.minZ, node.dividerY, node.maxX, node.dividerZ, node.maxY, &node);
			}

#ifdef DEBUG_AA_OCTREE
			info(true) << "Inside NE node";
#endif

			insert(*node.neNode, area);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		} else if (node.testInSWArea2(x, z, y, radius)) {
			if (node.swNode2 == nullptr) {
				node.swNode2 = makeUnique<ActiveAreaOctreeNode>(node.minX, node.dividerZ, node.minY, node.dividerX, node.maxZ, node.dividerY, &node);
			}

#ifdef DEBUG_AA_OCTREE
			info(true) << "Inside SW-2 node";
#endif

			insert(*node.swNode2, area);
		} else if (node.testInSEArea2(x, z, y, radius)) {
			if (node.seNode2 == nullptr) {
				node.seNode2 = makeUnique<ActiveAreaOctreeNode>(node.minX, node.dividerZ, node.minY, node.maxX, node.maxZ, node.dividerY, &node);
			}

#ifdef DEBUG_AA_OCTREE
			info(true) << "Inside SE-2 node";
#endif

			insert(*node.seNode2, area);
		} else if (node.testInNWArea2(x, z, y, radius)) {
			if (node.nwNode2 == nullptr) {
				node.nwNode2 = makeUnique<ActiveAreaOctreeNode>(node.minX, node.dividerZ, node.minY, node.dividerX, node.maxZ, node.maxY, &node);
			}

#ifdef DEBUG_AA_OCTREE
			info(true) << "Inside NW-2 node";
#endif

			insert(*node.nwNode2, area);
		} else if (node.testInNEArea2(x, z, y, radius)) {
			if (node.neNode2 == nullptr) {
				node.neNode2 = makeUnique<ActiveAreaOctreeNode>(node.minX, node.dividerZ, node.minY, node.maxX, node.maxZ, node.maxY, &node);
			}

#ifdef DEBUG_AA_OCTREE
			info(true) << "Inside NE-2 node";
#endif

			insert(*node.neNode2, area);
		} else {
#ifdef DEBUG_AA_OCTREE
			info(true) << "insert FINAL -- Inserting into node.";
#endif
			node.insertArea(area);
		}
	}
}

void ActiveAreaOctree::remove(Reference<ActiveArea*> area) {
#ifdef AREA_TREE_SIMPLE
	areas.drop(area);
}
#else
	removeActiveArea(*root, area);
#endif
}

void ActiveAreaOctree::removeActiveArea(ActiveAreaOctreeNode& node, ActiveArea* area) {
	node.dropArea(area);

	const auto& nodeSW = node.swNode;
	const auto& nodeSE = node.seNode;
	const auto& nodeNW = node.nwNode;
	const auto& nodeNE = node.neNode;

	const auto& nodeSW2 = node.swNode2;
	const auto& nodeSE2 = node.seNode2;
	const auto& nodeNW2 = node.nwNode2;
	const auto& nodeNE2 = node.neNode2;

	const float positionX = area->getPositionX();
	const float positionY = area->getPositionY();
	const float positionZ = area->getPositionZ();

	const float radius = area->getRadius();

	if (nodeSW != nullptr && nodeSW->testAreaInside(positionX, positionZ, positionY, radius)) {
		removeActiveArea(*nodeSW, area);
	} else if (nodeSE != nullptr && nodeSE->testAreaInside(positionX, positionZ, positionY, radius)) {
		removeActiveArea(*nodeSE, area);
	} else if (nodeNW != nullptr && nodeNW->testAreaInside(positionX, positionZ, positionY, radius)) {
		removeActiveArea(*nodeNW, area);
	} else if (nodeNE != nullptr && nodeNE->testAreaInside(positionX, positionZ, positionY, radius)) {
		removeActiveArea(*nodeNE, area);
	} else if (nodeSW2 != nullptr && nodeSW2->testAreaInside(positionX, positionZ, positionY, radius)) {
		removeActiveArea(*nodeSW2, area);
	} else if (nodeSE2 != nullptr && nodeSE2->testAreaInside(positionX, positionZ, positionY, radius)) {
		removeActiveArea(*nodeSE2, area);
	} else if (nodeNW2 != nullptr && nodeNW2->testAreaInside(positionX, positionZ, positionY, radius)) {
		removeActiveArea(*nodeNW2, area);
	} else if (nodeNE2 != nullptr && nodeNE2->testAreaInside(positionX, positionZ, positionY, radius)) {
		removeActiveArea(*nodeNE2, area);
	}
}
#endif
