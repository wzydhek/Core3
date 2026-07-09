#include "HarvesterObjectMessage6.h"

HarvesterObjectMessage6::HarvesterObjectMessage6(HarvesterObject* hino) : BaseLineMessage(hino->getObjectID(), 0x4F4E4948, 6, 0x05) {
	insertInt(0x42);

	insertInt(0); // counter of uint64's I believe.
	insertInt(0); // update count.

	setSize();
}