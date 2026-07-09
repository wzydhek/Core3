#include "SharedMissionDataObjectTemplate.h"

SharedMissionDataObjectTemplate::SharedMissionDataObjectTemplate() {
}

SharedMissionDataObjectTemplate::~SharedMissionDataObjectTemplate() {
}

void SharedMissionDataObjectTemplate::readObject(IffStream* iffStream) {
	uint32 nextType = iffStream->getNextFormType();

	if (nextType != 'SMSD') {
		// Logger::console.error("expecting SHOT got " + String::hexvalueOf((int)nextType));

		SharedIntangibleObjectTemplate::readObject(iffStream);

		return;
	}

	iffStream->openForm('SMSD');

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

	iffStream->closeForm('SMSD');
}