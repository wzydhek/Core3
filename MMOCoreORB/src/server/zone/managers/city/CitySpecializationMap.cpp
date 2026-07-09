#include "CitySpecializationMap.h"

void CitySpecializationMap::readObject(LuaObject* luaObject) {
	if (!luaObject->isValidTable())
		return;

	for (int i = 1; i <= luaObject->getTableSize(); ++i) {
		LuaObject spec = luaObject->getObjectAt(i);

		if (spec.isValidTable()) {
			CitySpecialization citySpec;
			citySpec.readObject(&spec);

			put(citySpec.getName(), citySpec);
		}

		spec.pop();
	}
}