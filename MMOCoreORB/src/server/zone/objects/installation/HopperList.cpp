#include "HopperList.h"

ManagedReference<ResourceContainer*> HopperList::set(int idx, const ManagedReference<ResourceContainer*>& newValue, DeltaMessage* message, int updates) {
	ManagedReference<ResourceContainer*> object = vector.set(idx, newValue);

	if (message != nullptr) {
		if (updates != 0)
			message->startList(updates, updateCounter += updates);

		message->insertByte(2);
		message->insertShort(idx);

		message->insertLong(newValue->getSpawnObject()->getObjectID());
		message->insertFloat(newValue->getQuantity());
	}

	return object;
}

bool HopperList::add(const ManagedReference<ResourceContainer*>& element, DeltaMessage* message, int updates) {
	bool val = vector.add(element);

	if (message != nullptr) {
		if (updates != 0)
			message->startList(updates, updateCounter += updates);

		message->insertByte(1);
		message->insertShort(vector.size() - 1);

		message->insertLong(element->getSpawnObject()->getObjectID());
		message->insertFloat(element->getQuantity());
	}

	return val;
}

void HopperList::insertToMessage(BaseMessage* msg) const {
	msg->insertInt(size());
	msg->insertInt(updateCounter);

	for (int i = 0; i < size(); ++i) {
		ResourceContainer* value = get(i);

		msg->insertLong(value->getSpawnObject()->getObjectID());
		msg->insertFloat(value->getQuantity());
	}
}