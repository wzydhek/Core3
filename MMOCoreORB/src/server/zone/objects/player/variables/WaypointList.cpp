#include "WaypointList.h"

int WaypointList::set(uint64 key, WaypointObject* value, DeltaMessage* message, int updates) {
	int pos = vectorMap.put(key, value);

	if (message != nullptr) {
		if (updates != 0)
			message->startList(updates, updateCounter += updates);

		message->insertByte(0);

		message->insertLong(key);
		value->insertToMessage(message);
	}

	return pos;
}

void to_json(nlohmann::json& j, const WaypointList& w) {
	const DeltaVectorMap<uint64, ManagedReference<WaypointObject*>>& vm = w;

	to_json(j, vm);
}

bool WaypointList::drop(const uint64& key, DeltaMessage* message, int updates) {
	if (!vectorMap.contains(key))
		return false;

	ManagedReference<WaypointObject*> value = vectorMap.get(key);

	vectorMap.drop(key);

	if (message != nullptr) {
		if (updates != 0)
			message->startList(updates, updateCounter += updates);

		message->insertByte(1);

		message->insertLong(key);
		value->insertToMessage(message);
	}

	return true;
}

bool WaypointList::update(const uint64& key, DeltaMessage* message, int updates) {
	if (!vectorMap.contains(key))
		return false;

	ManagedReference<WaypointObject*> value = vectorMap.get(key);

	if (message != nullptr) {
		if (updates != 0)
			message->startList(updates, updateCounter += updates);

		message->insertByte(2);

		message->insertLong(key);
		value->insertToMessage(message);
	}

	return true;
}

void WaypointList::insertToMessage(BaseMessage* msg) const {
	msg->insertInt(size());
	msg->insertInt(getUpdateCounter());

	for (int i = 0; i < size(); ++i) {
		const uint64& key = getKeyAt(i);
		const auto& value = getValueAt(i);

		msg->insertByte(0);
		msg->insertLong(key);
		value->insertToMessage(msg);
	}
}

uint64 WaypointList::find(const String& name) const {
	if (name.isEmpty())
		return 0;

	for (int i = 0; i < size(); ++i) {
		const uint64& key = getKeyAt(i);
		const auto& value = getValueAt(i);

		if (name == value->getCustomObjectName().toString())
			return key;
	}

	return 0;
}

uint64 WaypointList::getWaypointBySpecialType(const uint8 specialTypeID) const {
	if (specialTypeID == 0)
		return 0;

	for (int i = 0; i < vectorMap.size(); ++i) {
		const auto& value = vectorMap.elementAt(i).getValue();

		if (value->getSpecialTypeID() == specialTypeID)
			return value->getObjectID();
	}

	return 0;
}

WaypointObject* WaypointList::getWaypointAt(float x, float y, String planet) const {
	for (int i = 0; i < vectorMap.size(); ++i) {
		const auto& value = vectorMap.elementAt(i).getValue();

		if (value->getPositionX() == x && value->getPositionY() == y && value->getPlanetCRC() == planet.hashCode())
			return value;
	}

	return nullptr;
}