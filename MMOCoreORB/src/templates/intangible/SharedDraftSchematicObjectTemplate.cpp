#include "SharedDraftSchematicObjectTemplate.h"

SharedDraftSchematicObjectTemplate::SharedDraftSchematicObjectTemplate() {
}

SharedDraftSchematicObjectTemplate::~SharedDraftSchematicObjectTemplate() {
}

void SharedDraftSchematicObjectTemplate::readObject(IffStream* iffStream) {
	uint32 nextType = iffStream->getNextFormType();

	if (nextType != 'SDSC') {
		// Logger::console.error("expecting SHOT got " + String::hexvalueOf((int)nextType));

		SharedIntangibleObjectTemplate::readObject(iffStream);

		return;
	}

	iffStream->openForm('SDSC');

	uint32 derv = iffStream->getNextFormType();

	if (derv == 'DERV') {
		loadDerv(iffStream);

		derv = iffStream->getNextFormType();
	}

	/*while (derv != 0) {
			if (derv != '
		}*/

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

	iffStream->closeForm('SDSC');
}

void SharedDraftSchematicObjectTemplate::readObject(LuaObject* templateData) {
	SharedIntangibleObjectTemplate::readObject(templateData);
}