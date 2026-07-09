#include "ShaderFamily.h"

ShaderFamily ::~ShaderFamily() {
	while (shaderVars.size() > 0)
		delete shaderVars.remove(0);
}

void ShaderFamily ::readObject(IffStream* iffStream) {
	iffStream->openChunk('SFAM');

	familyId = iffStream->getInt();

	iffStream->getString(familyName);

	iffStream->getString(fileName);

	red = iffStream->getByte();
	green = iffStream->getByte();
	blue = iffStream->getByte();
	var7 = iffStream->getFloat();
	weight = iffStream->getFloat();

	int nLayers = iffStream->getInt();

	for (int i = 0; i < nLayers; ++i) {
		ShaderVar* var = new ShaderVar();
		iffStream->getString(var->name);
		var->weight = iffStream->getFloat();

		shaderVars.add(var);
	}

	iffStream->closeChunk('SFAM');
}