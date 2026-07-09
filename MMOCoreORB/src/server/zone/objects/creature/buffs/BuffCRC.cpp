#include "BuffCRC.h"
#include "../BuffAttribute.h"

uint32 BuffCRC::getMedicalBuff(uint8 attribute) {
	uint32 buffCRC = 0;

	switch (attribute) {
		case BuffAttribute::HEALTH:
			buffCRC = BuffCRC::MEDICAL_ENHANCE_HEALTH;
			break;
		case BuffAttribute::ACTION:
			buffCRC = BuffCRC::MEDICAL_ENHANCE_ACTION;
			break;
		case BuffAttribute::STRENGTH:
			buffCRC = BuffCRC::MEDICAL_ENHANCE_STRENGTH;
			break;
		case BuffAttribute::CONSTITUTION:
			buffCRC = BuffCRC::MEDICAL_ENHANCE_CONSTITUTION;
			break;
		case BuffAttribute::QUICKNESS:
			buffCRC = BuffCRC::MEDICAL_ENHANCE_QUICKNESS;
			break;
		case BuffAttribute::STAMINA:
			buffCRC = BuffCRC::MEDICAL_ENHANCE_STAMINA;
			break;
		case BuffAttribute::POISON:
			buffCRC = BuffCRC::MEDICAL_ENHANCE_POISON;
			break;
		case BuffAttribute::DISEASE:
			buffCRC = BuffCRC::MEDICAL_ENHANCE_DISEASE;
			break;
	}

	return buffCRC;
}