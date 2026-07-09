#include "InstallationObjectMessage6.h"

InstallationObjectMessage6::InstallationObjectMessage6(InstallationObject* inso) : TangibleObjectMessage6(inso, 0x494E534F, 0x05) {
	// insertShort(0x02); // opcount
	// insertInt(0); // ??
	/*insertInt(0x62); // ??
	insertInt(0); // defender list?
	insertInt(0); // update counter*/
	//{ insertInt(0); // defender id? }

	setSize();
}