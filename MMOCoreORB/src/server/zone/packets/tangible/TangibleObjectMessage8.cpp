#include "TangibleObjectMessage8.h"

TangibleObjectMessage8::TangibleObjectMessage8(const TangibleObject* tano) : BaseLineMessage(tano, 0x54414E4F, 8, 0x00) {
	setSize();
}