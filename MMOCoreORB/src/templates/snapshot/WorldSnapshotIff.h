/*
 * WorldSnapshotIff.h
 *
 *  Created on: Mar 30, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"
#include "templates/snapshot/WorldSnapshotNode.h"

class WorldSnapshotIff : public IffTemplate {
	Vector<WorldSnapshotNode> nodes;
	Vector<String> objectTemplateNameList;

public:
	WorldSnapshotIff();

	void readObject(IffStream* iffStream);

	int getNodeCount();

	WorldSnapshotNode* getNode(int idx);

	String getObjectTemplateName(int idx) const;
};
