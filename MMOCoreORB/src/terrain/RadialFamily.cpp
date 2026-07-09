#include "RadialFamily.h"

RadialFamily ::~RadialFamily() {
	while (data.size() > 0)
		delete data.remove(0);
}

void RadialFamily ::readObject(IffStream* iffStream) {
	iffStream->openChunk('RFAM');

	familyId = iffStream->getInt();

	iffStream->getString(familyName);

	red = iffStream->getByte();
	green = iffStream->getByte();
	blue = iffStream->getByte();
	weight = iffStream->getFloat();

	int var7 = iffStream->getInt(); // counter

	for (int i = 0; i < var7; i++) {
		RadialData* rdata = new RadialData();

		iffStream->getString(rdata->ascii);
		rdata->var1 = iffStream->getFloat();
		rdata->var2 = iffStream->getFloat();
		rdata->var3 = iffStream->getFloat();
		rdata->var4 = iffStream->getFloat();
		rdata->var5 = iffStream->getInt();
		rdata->var6 = iffStream->getFloat();
		rdata->var7 = iffStream->getFloat();
		rdata->var8 = iffStream->getInt();
		rdata->var9 = iffStream->getUnsignedInt();

		data.add(rdata);
	}

	iffStream->closeChunk('RFAM');
}