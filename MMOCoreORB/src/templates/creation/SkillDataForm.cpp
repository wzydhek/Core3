#include "SkillDataForm.h"

SkillDataForm::SkillDataForm() {
}

SkillDataForm::~SkillDataForm() {
}

void SkillDataForm::readObject(IffStream* iffStream) {
	iffStream->openForm('PFDT');

	uint32 version = iffStream->getNextFormType();
	Chunk* versionChunk = iffStream->openForm(version);

	switch (version) {
		case '0000': {
			Vector<Chunk*> chunks;
			versionChunk->getChildren(chunks);

			for (int i = 0; i < chunks.size(); ++i) {
				Chunk* data = chunks.get(i);

				String key;
				String value;

				data->readString(key);
				data->readString(value);

				professionInfoPaths.put(key, value);
			}
		} break;
	}

	iffStream->closeForm(version);
	iffStream->closeForm('PFDT');
}

int SkillDataForm::getTotalPaths() const {
	return professionInfoPaths.size();
}

const String& SkillDataForm::getPathBySkillName(const String& professionName) const {
	return professionInfoPaths.get(professionName);
}

const String& SkillDataForm::getSkillNameAt(int idx) const {
	const VectorMapEntry<String, String>* entry = &professionInfoPaths.elementAt(idx);

	return entry->getKey();
}