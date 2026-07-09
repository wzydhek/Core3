#include "CompositeVolume.h"
#include "BoundingVolumeFactory.h"

CompositeVolume::CompositeVolume() : bbox(Vector3(0, 0, 0), Vector3(0, 0, 0)) {
}

bool CompositeVolume::isCompositeVolume() {
	return true;
}

const AABB& CompositeVolume::getBoundingBox() const {
	return bbox;
}

void CompositeVolume::read(IffStream *iff) {
	iff->openForm('0000');
	uint32 chunks = iff->getSubChunksNumber();
	for(int i=0; i<chunks; i++) {
			Reference<BaseBoundingVolume*> volume = BoundingVolumeFactory::getVolume(iff);
			volumes.add(volume);
	}
	iff->closeForm('0000');
}

#ifdef OSG_RENDERER
osg::ref_ptr<osg::Node> CompositeVolume::draw() const {
	osg::ref_ptr<osg::Group> group(new osg::Group);

	for(int i=0; i<volumes.size(); i++) {
		group->addChild(volumes.get(i)->draw());
	}
	return group;
}
#endif
