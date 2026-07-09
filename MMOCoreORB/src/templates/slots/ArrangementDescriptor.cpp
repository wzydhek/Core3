#include "ArrangementDescriptor.h"

ArrangementDescriptor::ArrangementDescriptor() {
}

void ArrangementDescriptor::readObject(IffStream* iffStream) {
	iffStream->openForm('ARGD');
	uint32 version = iffStream->getNextFormType();
	Chunk* versionForm = iffStream->openForm(version);

	switch (version) {
		case '0000': {
			for (int i = 0; i < versionForm->getChunksSize(); ++i) {
				Chunk* arg = iffStream->openChunk('ARG ');
				Vector<String> slot;

				while (arg->hasData()) {
					String slotName;
					arg->readString(slotName);

					slot.add(slotName);
				}

				arrangementSlots.add(slot);

				iffStream->closeChunk('ARG ');
			}
		}

		break;
	}

	iffStream->closeForm(version);
	iffStream->closeForm('ARGD');
}

void ArrangementDescriptor::clone(Vector<Vector<String>>& copyVec) const {
	arrangementSlots.clone(copyVec);
}

const Vector<Vector<String>>& ArrangementDescriptor::getArrangementSlots() const {
	return arrangementSlots;
}