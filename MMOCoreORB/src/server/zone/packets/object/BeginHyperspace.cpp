#include "BeginHyperspace.h"

BeginHyperspaceMessage::BeginHyperspaceMessage(uint64 objid, const String& location, float x, float y, float z) : ObjectControllerMessage(objid, 0x1B, 0x3FE) {
	insertAscii(location);
	insertFloat(x);
	insertFloat(z);
	insertFloat(y);
}