#include "ResourceContainerObjectDeltaMessage6.h"

ResourceContainerObjectDeltaMessage6::ResourceContainerObjectDeltaMessage6(ResourceContainer* rcno) : DeltaMessage(rcno->getObjectID(), 0x52434E4F, 6) {
	// Causes CTD, needs research.
	// setResourceName(rcno->getName());
	// setResourceType(rcno->getTemplateName());
	// close();
}

void ResourceContainerObjectDeltaMessage6::setResourceName(UnicodeString& resource_name) {
	startUpdate(0x06);
	insertUnicode(resource_name);
}

void ResourceContainerObjectDeltaMessage6::setResourceType(String& resource_type) {
	startUpdate(0x05);
	insertAscii(resource_type);
}