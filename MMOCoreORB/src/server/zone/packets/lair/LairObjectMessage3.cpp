#include "LairObjectMessage3.h"

LairObjectMessage3::LairObjectMessage3(LairObject* tano) : TangibleObjectMessage3(tano, 0x54414E4F, 0x0D) {
	setSize();
}