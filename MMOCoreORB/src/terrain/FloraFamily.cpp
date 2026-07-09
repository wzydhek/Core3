#include "FloraFamily.h"

FloraFamily ::~FloraFamily() {
	while (data.size() > 0)
		delete data.remove(0);
}

void FloraFamily ::readObject(IffStream* iffStream) {
	iffStream->openChunk('FFAM');

	familyId = iffStream->getInt();
	iffStream->getString(familyName);

	red = iffStream->getByte();
	green = iffStream->getByte();
	blue = iffStream->getByte();
	weight = iffStream->getFloat();
	isAquatic = iffStream->getUnsignedInt();

	int var8 = iffStream->getInt(); // counter

	for (int i = 0; i < var8; ++i) {
		FloraData* floraData = new FloraData();

		iffStream->getString(floraData->name);
		floraData->var1 = iffStream->getFloat();
		floraData->var2 = iffStream->getUnsignedInt();
		floraData->var3 = iffStream->getFloat();
		floraData->var4 = iffStream->getFloat();
		floraData->var5 = iffStream->getUnsignedInt();
		floraData->var6 = iffStream->getInt();
		floraData->var7 = iffStream->getFloat();
		floraData->var8 = iffStream->getFloat();

		data.add(floraData);
	}

	iffStream->closeChunk('FFAM');
}