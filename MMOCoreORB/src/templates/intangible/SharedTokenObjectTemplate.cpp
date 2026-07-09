#include "SharedTokenObjectTemplate.h"

SharedTokenObjectTemplate::SharedTokenObjectTemplate() {
}

SharedTokenObjectTemplate::~SharedTokenObjectTemplate() {
}

void SharedTokenObjectTemplate::readObject(IffStream* iffStream) {
	uint32 nextType = iffStream->getNextFormType();

	if (nextType != 'STOK') {
		// Logger::console.error("expecting SHOT got " + String::hexvalueOf((int)nextType));

		SharedIntangibleObjectTemplate::readObject(iffStream);

		return;
	}

	iffStream->openForm('STOK');

	uint32 derv = iffStream->getNextFormType();

	if (derv == 'DERV') {
		loadDerv(iffStream);

		derv = iffStream->getNextFormType();
	}

	iffStream->openForm(derv);

	try {
		// parseFileData(iffStream);
	} catch (Exception& e) {
		String msg;
		msg += "exception caught parsing file data ->";
		msg += e.getMessage();

		Logger::console.error(msg);
	}

	iffStream->closeForm(derv);

	if (iffStream->getRemainingSubChunksNumber() > 0) {
		readObject(iffStream);
	}

	iffStream->closeForm('STOK');
}