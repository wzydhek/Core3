/*
 * DetailVolume.h
 *
 *  Created on: 03/20/2016
 *      Author: gslomin
 */

#pragma once

#include "CompositeVolume.h"

class DetailVolume : public CompositeVolume {
public:
	bool isDetailVolume();

	DetailVolume();

	virtual void read(IffStream *iff);

#ifdef OSG_RENDERER
	virtual osg::ref_ptr<osg::Node> draw() const;
#endif
};
