#include "ProfessionDefaultsInfo.h"

ProfessionDefaultsInfo::ProfessionDefaultsInfo() : Object() {
	skill = nullptr;

	professionItems.setNoDuplicateInsertPlan();
	professionMods.setNoDuplicateInsertPlan();
}

ProfessionDefaultsInfo::~ProfessionDefaultsInfo() {
}

void ProfessionDefaultsInfo::readObject(IffStream* iffStream) {
	iffStream->openForm('PRFI');

	uint32 version = iffStream->getNextFormType();
	Chunk* chunk = iffStream->openForm(version);
	switch (version) {
		case '0000': {
			String skillName;
			iffStream->openForm('SKLS');
			Chunk* skil = iffStream->openChunk('SKIL');
			skil->readString(skillName);
			iffStream->closeChunk('SKIL');
			iffStream->closeForm('SKLS');

			SkillManager* skillManager = SkillManager::instance();
			skill = skillManager->getSkill(skillName);

			// Load the individual clothing templates.
			for (int i = 1; i < chunk->getChunksSize(); ++i) {
				Chunk* chunkPTMP = iffStream->openForm('PTMP');
				Chunk* chunkName = iffStream->openChunk('NAME');
				String ptmpName;
				chunkName->readString(ptmpName);
				iffStream->closeChunk('NAME');

				SortedVector<String> items;

				for (int j = 1; j < chunkPTMP->getChunksSize(); ++j) {
					Chunk* chunkItem = iffStream->openChunk('ITEM');
					int unk1 = chunkItem->readInt();
					String itemTemplate;
					chunkItem->readString(itemTemplate);
					itemTemplate = itemTemplate.replaceFirst("shared_", "");
					iffStream->closeChunk('ITEM');
					items.put(itemTemplate);
				}

				professionItems.put(ptmpName, items);
				iffStream->closeChunk('PTMP');
			}
		} break;
	}

	iffStream->closeForm(version);
	iffStream->closeForm('PRFI');
}

void ProfessionDefaultsInfo::setAttributeMod(uint8 idx, int value) {
	professionMods.put(idx, value);
}

const SortedVector<String>* ProfessionDefaultsInfo::getProfessionItems(const String& clientTemplate) const {
	if (!professionItems.contains(clientTemplate))
		return nullptr;

	return &professionItems.get(clientTemplate);
}

const Skill* ProfessionDefaultsInfo::getSkill() const {
	return skill;
}

int ProfessionDefaultsInfo::getAttributeMod(uint8 idx) const {
	return professionMods.get(idx);
}

const Vector<String>* ProfessionDefaultsInfo::getStartingItems() const {
	return &startingItems;
}

Vector<String>* ProfessionDefaultsInfo::getStartingItems() {
	return &startingItems;
}