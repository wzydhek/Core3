#include "PlanetTravelPointList.h"
#include "server/zone/objects/region/CityRegion.h"

PlanetTravelPointList::PlanetTravelPointList() : VectorMap<String, Reference<PlanetTravelPoint*>>() {
	setNoDuplicateInsertPlan();
	setNullValue(nullptr);
}

Reference<PlanetTravelPoint*> PlanetTravelPointList::get(int index) {
	ReadLocker guard(this);

	Reference<PlanetTravelPoint*> point = VectorMap<String, Reference<PlanetTravelPoint*>>::get(index);

	return point;
}

Reference<PlanetTravelPoint*> PlanetTravelPointList::get(const String& name) {
	ReadLocker guard(this);

	Reference<PlanetTravelPoint*> point = VectorMap<String, Reference<PlanetTravelPoint*>>::get(name);

	return point;
}

void PlanetTravelPointList::insertToMessage(BaseMessage* message, PlanetTravelPoint* origin) {
	rlock();

	int totalPoints = size();

	// #ifdef PLATFORM_WIN
	//		char* incomingAllowed = (char*) _malloca(totalPoints);
	// #else
	Vector<bool> incomingAllowed;
	// #endif
	int insertionPoints = totalPoints;

	for (int i = 0; i < totalPoints; ++i) {
		Reference<PlanetTravelPoint*> ptp = VectorMap<String, Reference<PlanetTravelPoint*>>::get(i);

		bool incoming = ptp->isIncomingAllowed();
		incomingAllowed.add(incoming);

		if (!incoming) {
			insertionPoints--;
		}
	}

	message->insertInt(insertionPoints);

	for (int i = 0; i < totalPoints; ++i) {
		if (incomingAllowed.get(i))
			message->insertAscii(VectorMap<String, Reference<PlanetTravelPoint*>>::get(i)->getPointName());
	}

	message->insertInt(insertionPoints);

	for (int i = 0; i < totalPoints; ++i) {
		if (incomingAllowed.get(i)) {
			Reference<PlanetTravelPoint*> ptp = VectorMap<String, Reference<PlanetTravelPoint*>>::get(i);
			message->insertFloat(ptp->getArrivalPositionX());
			message->insertFloat(ptp->getArrivalPositionZ());
			message->insertFloat(ptp->getArrivalPositionY());
		}
	}

	message->insertInt(insertionPoints);

	for (int i = 0; i < totalPoints; ++i) {
		if (incomingAllowed.get(i)) {
			Reference<PlanetTravelPoint*> ptp = VectorMap<String, Reference<PlanetTravelPoint*>>::get(i);
			ManagedReference<CreatureObject*> shuttle = ptp->getShuttle();
			if (shuttle == nullptr) {
				message->insertInt(0);
				continue;
			}

			ManagedReference<CityRegion*> city = shuttle->getCityRegion().get();

			if (city == nullptr) {
				message->insertInt(0);
				continue;
			}

			if (ptp == origin)
				message->insertInt(city->getTravelTax());
			else
				message->insertInt(0);
		}
	}

	message->insertInt(insertionPoints);

	for (int i = 0; i < totalPoints; ++i) {
		if (incomingAllowed.get(i))
			message->insertByte((byte)VectorMap<String, Reference<PlanetTravelPoint*>>::get(i)->isInterplanetary());
	}

	// #ifdef PLATFORM_WIN
	//		_freea(incomingAllowed);
	// #endif

	runlock();
}

void PlanetTravelPointList::readLuaObject(LuaObject* luaObject) {
	wlock();

	if (!luaObject->isValidTable())
		return;

	for (int i = 1; i <= luaObject->getTableSize(); ++i) {
		lua_State* L = luaObject->getLuaState();
		lua_rawgeti(L, -1, i);

		LuaObject planetTravelPointEntry(L);

		Reference<PlanetTravelPoint*> ptp = new PlanetTravelPoint(zoneName);
		ptp->readLuaObject(&planetTravelPointEntry);

		put(ptp->getPointName(), ptp);

		planetTravelPointEntry.pop();
	}

	unlock();
}

void PlanetTravelPointList::setZoneName(const String& name) {
	zoneName = name;
}

void PlanetTravelPointList::addPlayerCityTravelPoint(PlanetTravelPoint* planetTravelPoint) {
	wlock();

	put(planetTravelPoint->getPointName(), planetTravelPoint);

	unlock();
}

void PlanetTravelPointList::removePlayerCityTravelPoint(const String& pointName) {
	wlock();

	drop(pointName);

	unlock();
}