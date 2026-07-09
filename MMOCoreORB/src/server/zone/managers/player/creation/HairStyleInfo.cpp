#include "HairStyleInfo.h"

HairStyleInfo::HairStyleInfo() {
}

HairStyleInfo::~HairStyleInfo() {
}

HairStyleInfo& HairStyleInfo::operator=(const HairStyleInfo& hsi) {
	if (this == &hsi)
		return *this;

	playerTemplate = hsi.playerTemplate;
	styles = hsi.styles;

	return *this;
}

/**
 * @pre: iffStream advanced to a PTMP form.
 */
void HairStyleInfo::readObject(IffStream* iffStream) {
	if (iffStream->getNextFormType() != 'PTMP')
		return;

	Chunk* ptmp = iffStream->openForm('PTMP');

	Vector<Chunk*> children;
	ptmp->getChildren(children);

	for (int i = 0; i < children.size(); ++i) {
		Chunk* chunk = children.get(i);

		switch (chunk->getChunkID()) {
			case 'NAME':
				chunk->readString(playerTemplate);
				break;
			case 'ITMS': {
				while (chunk->hasData()) {
					String hairTemplate;
					chunk->readString(hairTemplate);
					styles.add(hairTemplate);
				}
			} break;
		}
	}

	iffStream->closeForm('PTMP');
}

bool HairStyleInfo::hasStyle(const String& style) const {
	for (int i = 0; i < styles.size(); ++i) {
		if (styles.get(i) == style)
			return true;
	}

	return false;
}

int HairStyleInfo::getTotalStyles() const {
	return styles.size();
}

const String& HairStyleInfo::getPlayerTemplate() const {
	return playerTemplate;
}