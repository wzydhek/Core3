#include "TangibleObjectMessage7.h"

TangibleObjectMessage7::TangibleObjectMessage7(const TangibleObject* tano) : BaseLineMessage(tano, 0x54414E4F, 7, 0x02) {
	insertLong(0);
	insertLong(0);

	setSize();
}