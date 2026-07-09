#include "server/zone/ActiveAreaQuadTree.h"
#include "engine/log/Logger.h"
#include "server/zone/objects/area/areashapes/RectangularAreaShape.h"

using namespace server::zone;

ActiveAreaQuadTreeNode::ActiveAreaQuadTreeNode(float minx, float miny, float maxx, float maxy, const ActiveAreaQuadTreeNode* parent) : minX(minx), minY(miny), maxX(maxx), maxY(maxy), parentNode(parent) {
	dividerX = (minX + maxX) / 2;
	dividerY = (minY + maxY) / 2;

	areas.setNoDuplicateInsertPlan();

	setLoggingName("ActiveAreaQuadTreeNode");
}

bool ActiveAreaQuadTreeNode::isEmpty() const {
	return areas.isEmpty();
}

void ActiveAreaQuadTreeNode::insertArea(ActiveArea* area) {
	areas.put(area);
}

void ActiveAreaQuadTreeNode::dropArea(ActiveArea* area) {
	areas.drop(area);
}

bool ActiveAreaQuadTreeNode::testInside(float x, float y) const {
	return x >= minX && x < maxX && y >= minY && y < maxY;
}

bool ActiveAreaQuadTreeNode::testAreaInside(float x, float y, float radius) const {
	float xDelta1 = x - radius;
	float xDelta2 = x + radius;
	float yDelta1 = y - radius;
	float yDelta2 = y + radius;

	bool runTest = (xDelta1 >= minX && xDelta2 < maxX && yDelta1 >= minY && yDelta2 < maxY);
	return runTest;
}

bool ActiveAreaQuadTreeNode::testAreaInsideRectangle(ActiveArea* area) const {
	if (area == nullptr)
		return false;

	Vector3 center = area->getAreaCenter();
	Vector4 bounds = area->getRectangularDimensions();

	float width = area->getWidth();
	float height = area->getHeight();
	float radius = area->getRadius();

	float llX = bounds[0];
	float llY = bounds[1];
	float urX = bounds[2];
	float urY = bounds[3];

	bool runTest = (llX >= minX && urX < maxX && llY >= minY && urY < maxY);

	// info(true) << "testAreaInside -- llX = " << llX << " llY = " << llY << " urX = " << urX << " urY = " << urY;

	return runTest;
}

bool ActiveAreaQuadTreeNode::hasSubNodes() const {
	return nwNode || neNode || swNode || seNode;
}

bool ActiveAreaQuadTreeNode::testInSWArea(float x, float y, float radius) const {
	return (x - radius) >= minX && (x + radius) < dividerX && (y - radius) >= minY && (y + radius) < dividerY;
}

bool ActiveAreaQuadTreeNode::testInSEArea(float x, float y, float radius) const {
	return (x - radius) >= dividerX && (x + radius) < maxX && (y - radius) >= minY && (y + radius) < dividerY;
}

bool ActiveAreaQuadTreeNode::testInNWArea(float x, float y, float radius) const {
	return (x - radius) >= minX && (x + radius) < dividerX && (y - radius) >= dividerY && (y + radius) < maxY;
}

bool ActiveAreaQuadTreeNode::testInNEArea(float x, float y, float radius) const {
	return (x - radius) >= dividerX && (x + radius) < maxX && (y - radius) >= dividerY && (y + radius) < maxY;
}

ActiveAreaQuadTree::ActiveAreaQuadTree(float minx, float miny, float maxx, float maxy) {
#ifndef AREA_TREE_SIMPLE
	root = makeUnique<ActiveAreaQuadTreeNode>(minx, miny, maxx, maxy, nullptr);
#else
	areas.setNoDuplicateInsertPlan();
#endif

	setLoggingName("ActiveAreaQuadTree");
}

void ActiveAreaQuadTree::insert(Reference<ActiveArea*> area) {
#ifndef AREA_TREE_SIMPLE
	insert(*root, area);
#else
	areas.put(std::move(area));
#endif
}

#ifndef AREA_TREE_SIMPLE

void ActiveAreaQuadTree::insert(ActiveAreaQuadTreeNode& node, ActiveArea* area) {
	//info(true) << "ActiveAreaQuadTree::insert -- called " << area->getAreaName() << " Center Point = " << area->getAreaCenter().toString() << " Radius = " << area->getRadius();
	//info(true) << "ActiveAreaQuadTree::insert  -- Node Info: minX = " << node.minX << " minY = " << node.minY << " maxX = " << node.maxX << " maxY = " << node.maxY << " DividerX = " << node.dividerX << " dividerY = " << node.dividerY;

	/*if (area->isRectangularAreaShape()) {
		RectangularAreaShape* rect = cast<RectangularAreaShape*>(area->getAreaShape());

		info(true) << "ActiveAreaQuadTree::insert  --  Rectangle Info = ";
		 rect->logDimensions();
	}*/

	if (!node.hasSubNodes()) {
		if ((node.maxX - node.minX <= 8) && (node.maxY - node.minY <= 8)) {
			node.insertArea(area);

			return;
		}
	}

	Vector3 location = area->getAreaCenter();
	const float x = location.getX();
	const float y = location.getY();
	const float radius = area->getRadius();
	bool isRectangle = area->isRectangularAreaShape();

	if ((isRectangle && node.testAreaInsideRectangle(area)) || node.testAreaInside(x, y, radius)) {
		if (node.testInSWArea(x, y, radius)) {
			if (node.swNode == nullptr) {
				node.swNode = makeUnique<ActiveAreaQuadTreeNode>(node.minX, node.minY, node.dividerX, node.dividerY, &node);
			}

			insert(*node.swNode, area);
		} else if (node.testInNWArea(x, y, radius)) {
			if (node.nwNode == nullptr)
				node.nwNode = makeUnique<ActiveAreaQuadTreeNode>(node.minX, node.dividerY, node.dividerX, node.maxY, &node);

			insert(*node.nwNode, area);
		} else if (node.testInSEArea(x, y, radius)) {
			if (node.seNode == nullptr)
				node.seNode = makeUnique<ActiveAreaQuadTreeNode>(node.dividerX, node.minY, node.maxX, node.dividerY, &node);

			insert(*node.seNode, area);
		} else if (node.testInNEArea(x, y, radius)) {
			if (node.neNode == nullptr)
				node.neNode = makeUnique<ActiveAreaQuadTreeNode>(node.dividerX, node.dividerY, node.maxX, node.maxY, &node);

			insert(*node.neNode, area);
		} else {
			node.insertArea(area);
		}
	}

	return;
}

void ActiveAreaQuadTree::remove(Reference<ActiveArea*> area) {
#ifdef AREA_TREE_SIMPLE
	areas.drop(area);
#else
	removeActiveArea(*root, area);
#endif
}

void ActiveAreaQuadTree::removeActiveArea(ActiveAreaQuadTreeNode& node, ActiveArea* area) {
	node.dropArea(area);

	const auto& nodeSW = node.swNode;
	const auto& nodeSE = node.seNode;
	const auto& nodeNW = node.nwNode;
	const auto& nodeNE = node.neNode;

	const float positionX = area->getPositionX();
	const float positionY = area->getPositionY();
	const float radius = area->getRadius();

	if (nodeSW != nullptr && nodeSW->testAreaInside(positionX, positionY, radius)) {
		removeActiveArea(*nodeSW, area);
	} else if (nodeSE != nullptr && nodeSE->testAreaInside(positionX, positionY, radius)) {
		removeActiveArea(*nodeSE, area);
	} else if (nodeNW != nullptr && nodeNW->testAreaInside(positionX, positionY, radius)) {
		removeActiveArea(*nodeNW, area);
	} else if (nodeNE != nullptr && nodeNE->testAreaInside(positionX, positionY, radius)) {
		removeActiveArea(*nodeNE, area);
	}
}
#endif
