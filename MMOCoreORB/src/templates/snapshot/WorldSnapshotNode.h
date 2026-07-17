/*
 * WorldSnapshotNode.h
 *
 *  Created on: Mar 31, 2011
 *      Author: crush
 */

#pragma once

#include "engine/util/u3d/Quaternion.h"
#include "engine/util/iffstream/IffStream.h"

namespace templates {
namespace snapshot {

class WorldSnapshotNode : public Object {
	Vector<WorldSnapshotNode> childNodes;

	uint32 objectID;
	uint32 parentID;
	uint32 nameID;
	uint32 cellid; //cellid in the cells

	Quaternion direction;
	Vector3 position;

	float gameObjectType;
	uint32 unknown2;

public:
	WorldSnapshotNode();

	WorldSnapshotNode(const WorldSnapshotNode& wsn);

	WorldSnapshotNode& operator=(const WorldSnapshotNode& wsn);

	void parse(IffStream* iffStream);

	Quaternion getDirection() const;

	float getGameObjectType() const;

	uint32 getNameID() const;

	uint32 getObjectID() const;

	uint32 getParentID() const;

	Vector3 getPosition() const;

	uint32 getCellID() const;

	uint32 getUnknown2() const;

	int getNodeCount();

	WorldSnapshotNode* getNode(int idx);
};

} // namespace snapshot
} // namespace templates

using namespace templates::snapshot;
