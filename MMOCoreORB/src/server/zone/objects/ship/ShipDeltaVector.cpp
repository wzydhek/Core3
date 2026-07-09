/*
*
* ShipDeltaVector.cpp
*
*/

#include "server/zone/objects/ship/ShipDeltaVector.h"
#include "server/zone/objects/ship/ShipObject.h"

ShipDeltaVector::ShipDeltaVector(SceneObject* ship, SceneObject* player) : Object() {
	deltaVector.setNoDuplicateInsertPlan();
	deltaVector.setNullValue(nullptr);

	objectID = ship->getObjectID();
	playerID = player != nullptr ? player->getObjectID() : 0;
}

ShipDeltaVector::~ShipDeltaVector() {
	reset();
}

int ShipDeltaVector::getDeltaType(uint32 deltaID) {
	switch (deltaID) {
		case DeltaTypeID::Delta1:
			return DeltaType::Private;
		case DeltaTypeID::Delta3:
			return DeltaType::Public;
		case DeltaTypeID::Delta4:
			return DeltaType::Private;
		case DeltaTypeID::Delta6:
			return DeltaType::Public;
	}

	return DeltaTypeID::None;
}

void ShipDeltaVector::sendMessages(ShipObject* ship) {
	Locker lock(&deltaMutex);

	auto owner = ship->getOwner().get();

	for (int i = 0; i < deltaVector.size(); ++i) {
		auto deltaID = deltaVector.elementAt(i).getKey();
		auto message = deltaVector.elementAt(i).getValue();

		if (message == nullptr) {
			continue;
		}

		message->close();

		int deltaType = getDeltaType(deltaID);

		if (deltaType == DeltaType::Private) {
			if (owner != nullptr) {
				owner->sendMessage(message->clone());
			}

			ship->sendMembersBaseMessage(message->clone(), false);
		} else if (deltaType == DeltaType::Public) {
			ship->broadcastMessage(message->clone(), true);
		}
	}

	reset();
}

void ShipDeltaVector::reset(SceneObject* player) {
	Locker lock(&deltaMutex);

	playerID = player != nullptr ? player->getObjectID() : 0;

	for (int i = deltaVector.size() - 1; i >= 0; --i) {
		auto message = deltaVector.elementAt(i).getValue();

		if (message != nullptr) {
			delete message;
			message = nullptr;
		}

		deltaVector.remove(i);
	}
}

DeltaMessage* ShipDeltaVector::getMessage(uint32 deltaID) {
	Locker lock(&deltaMutex);

	int deltaType = getDeltaType(deltaID);

	if (deltaType == DeltaTypeID::None || (deltaType == DeltaType::Private && playerID == DeltaTypeID::None)) {
		return nullptr;
	}

	auto delta = deltaVector.get(deltaID);

	if (delta != nullptr) {
		return delta;
	}

	delta = new DeltaMessage(objectID, 'SHIP', deltaID);
	deltaVector.put(deltaID, delta);

	return delta;
}

int ShipDeltaVector::size() {
	ReadLocker lock(&deltaMutex);

	return deltaVector.size();
}