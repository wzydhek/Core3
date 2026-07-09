#include "ResourceContainerObjectDeltaMessage3.h"

ResourceContainerObjectDeltaMessage3::ResourceContainerObjectDeltaMessage3(ResourceContainer* rcno) : DeltaMessage(rcno->getObjectID(), 0x52434E4F, 3) {
	container = rcno;
}
/*
 * Need More Research.
 *
 * void setContainerType(String& file, String& ctype) {
 * 	startUpdate(0x01);
 * 	insertAscii(file);
 * 	insertInt(0);
 * 	insertAscii(ctype);
 * }
 *
 * void setResourceID(uint64 rid) {
 * 	addLongUpdate(0x0E, rid);
 * }
 */

void ResourceContainerObjectDeltaMessage3::updateQuantity() {
	addIntUpdate(0x0B, container->getQuantity());
}