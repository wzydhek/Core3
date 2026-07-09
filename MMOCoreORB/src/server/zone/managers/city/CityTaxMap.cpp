#include "CityTaxMap.h"

void CityTaxMap::readObject(LuaObject* luaObject) {
	if (!luaObject->isValidTable())
		return;

	for (int i = 1; i <= luaObject->getTableSize(); ++i) {
		LuaObject obj = luaObject->getObjectAt(i);

		if (obj.isValidTable()) {
			CityTax tax;
			tax.readObject(&obj);
			add(tax);
		}

		obj.pop();
	}
}