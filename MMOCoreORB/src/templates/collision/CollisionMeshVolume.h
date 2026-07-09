/*
 * CollisionMeshVolume.h
 *
 *  Created on: 03/20/2016
 *      Author: gslomin
 */

#pragma once

#include "BaseBoundingVolume.h"

class CollisionMeshVolume : public BaseBoundingVolume {
protected:
	Vector<Vector3> verts;
	Vector<unsigned int> indicies;
	AABB bbox;
public:
	bool isCollisionMesh();
	
	CollisionMeshVolume();
	
	virtual void read(IffStream* iff);

	const AABB& getBoundingBox() const;

#ifdef OSG_RENDERER
	virtual osg::ref_ptr<osg::Node> draw() const;
#endif
};
