/*
 * CompositeVolume.h
 *
 *  Created on: 03/20/2016
 *      Author: gslomin
 */

#pragma once

#include "BaseBoundingVolume.h"

class CompositeVolume : public BaseBoundingVolume {
protected:
	Vector<Reference<BaseBoundingVolume*> > volumes;
	AABB bbox;
public:
	bool isCompositeVolume();

	CompositeVolume();

	const AABB& getBoundingBox() const;

	virtual void read(IffStream *iff);
#ifdef OSG_RENDERER
	virtual osg::ref_ptr<osg::Node> draw() const;
#endif
};
