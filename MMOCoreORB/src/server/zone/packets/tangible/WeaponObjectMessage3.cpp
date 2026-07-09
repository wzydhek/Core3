#include "WeaponObjectMessage3.h"

WeaponObjectMessage3::WeaponObjectMessage3(WeaponObject* weao) : TangibleObjectMessage3(weao, 0x5745414F, 0x11) {
	/*insertInt(0xE8000000);

	insertInt(3);
	insertInt(0);
	insertInt(0);

	insertFloat(5);

	insertInt(0);
	insertInt(0);
	insertInt(0);*/

	setSize();
}