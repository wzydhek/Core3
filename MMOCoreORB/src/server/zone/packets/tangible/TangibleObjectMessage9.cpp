#include "TangibleObjectMessage9.h"

TangibleObjectMessage9::TangibleObjectMessage9(const TangibleObject* tano) : BaseLineMessage(tano, 0x54414E4F, 9, 0x00) {
	setSize();
}