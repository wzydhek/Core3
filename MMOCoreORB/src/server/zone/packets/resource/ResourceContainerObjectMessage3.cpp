#include "ResourceContainerObjectMessage3.h"

ResourceContainerObjectMessage3::ResourceContainerObjectMessage3(ResourceContainer* rcno) : TangibleObjectMessage3(rcno, 0x52434E4F, 0x0F) {
	insertInt(rcno->getQuantity()); // Stack Size
	insertLong(rcno->getSpawnID()); // ResourceID

	setSize();
}