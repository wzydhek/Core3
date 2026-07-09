#include "SlotDescriptor.h"

SlotDescriptor::SlotDescriptor() {
}

void SlotDescriptor::readObject(IffStream* iffStream) {
	iffStream->openForm('SLTD');
	uint32 version = iffStream->getNextFormType();
	iffStream->openForm(version);

	switch (version) {
		case '0000': {
			Chunk* data = iffStream->openChunk('DATA');

			while (data->hasData()) {
				String slotName;
				data->readString(slotName);
				slots.add(slotName);
			}

			iffStream->closeChunk('DATA');
		} break;
	}

	iffStream->closeForm(version);
	iffStream->closeForm('SLTD');
}

void SlotDescriptor::clone(Vector<String>& copyVec) const {
	slots.clone(copyVec);
}

const Vector<String>* SlotDescriptor::getSlots() const {
	return &slots;
}