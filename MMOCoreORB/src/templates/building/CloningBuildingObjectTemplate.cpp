#include "CloningBuildingObjectTemplate.h"

CloningBuildingObjectTemplate::CloningBuildingObjectTemplate() {
	facilityType = 0;
}

CloningBuildingObjectTemplate::~CloningBuildingObjectTemplate() {
}

void CloningBuildingObjectTemplate::readObject(LuaObject* templateData) {
	SharedBuildingObjectTemplate::readObject(templateData);

	spawningPoints.removeAll();

	LuaObject luaItemList = templateData->getObjectField("spawningPoints");

	int size = luaItemList.getTableSize();

	lua_State* L = luaItemList.getLuaState();

	for (int i = 0; i < size; ++i) {
		lua_rawgeti(L, -1, i + 1);
		LuaObject a(L);

		CloneSpawnPoint point;
		point.parseFromLua(&a);

		// System::out << "adding spawning point" << endl;

		spawningPoints.add(point);

		a.pop();
	}

	luaItemList.pop();

	facilityType = templateData->getIntField("facilityType");
}

CloneSpawnPoint* CloningBuildingObjectTemplate::getRandomSpawnPoint() {
	if (spawningPoints.size() == 0)
		return nullptr;

	return &spawningPoints.get(System::random(spawningPoints.size() - 1));
}

bool CloningBuildingObjectTemplate::isCloningBuildingObjectTemplate() {
	return true;
}

int CloningBuildingObjectTemplate::getFacilityType() {
	return facilityType;
}

bool CloningBuildingObjectTemplate::isJediCloner() {
	return facilityType == JEDI_ONLY || facilityType == LIGHT_JEDI_ONLY || facilityType == DARK_JEDI_ONLY;
}

Vector<CloneSpawnPoint>* CloningBuildingObjectTemplate::getCloneSpawnPoints() {
	return &spawningPoints;
}