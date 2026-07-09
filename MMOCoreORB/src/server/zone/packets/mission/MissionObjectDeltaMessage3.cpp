#include "MissionObjectDeltaMessage3.h"

MissionObjectDeltaMessage3::MissionObjectDeltaMessage3(MissionObject* mi) : DeltaMessage(mi->getObjectID(), 0x4D49534F, 3) {
	miso = mi;
}

void MissionObjectDeltaMessage3::updateDescriptionStf(StringId* stringId) {
	startUpdate(0x0B);

	insertAscii(stringId->getFile());
	insertInt(0);
	insertAscii(stringId->getStringID());
}

void MissionObjectDeltaMessage3::updateTitleStf(StringId* stringId) {
	startUpdate(0x0C);

	insertAscii(stringId->getFile());
	insertInt(0);
	insertAscii(stringId->getStringID());
}

void MissionObjectDeltaMessage3::updateTargetName(const String& name) {
	startUpdate(0x0F);

	insertAscii(name);
}

void MissionObjectDeltaMessage3::updateDifficultyLevel(int diff) {
	startUpdate(0x05);

	insertInt(diff);
}

void MissionObjectDeltaMessage3::updateRewardCredits(int creds) {
	startUpdate(0x08);

	insertInt(creds);
}

void MissionObjectDeltaMessage3::updateRefreshCount(uint32 trc) {
	startUpdate(0x0D);

	// insertInt(miso->getRefreshCount());
	insertInt(trc);
}

void MissionObjectDeltaMessage3::updateTypeCRC(uint32 crc) {
	startUpdate(0x0E);

	insertInt(crc);
}

void MissionObjectDeltaMessage3::updateTemplateCRC(uint32 crc) {
	startUpdate(0x0A);

	insertInt(crc);
}

void MissionObjectDeltaMessage3::updateStartPosition(float posX, float posZ, float posY, uint32 crc) {
	startUpdate(0x09);

	insertFloat(posX);
	insertFloat(posZ);
	insertFloat(posY);
	insertLong(0); //?
	insertInt(crc);
}

void MissionObjectDeltaMessage3::updateDestination(float posX, float posZ, float posY, uint32 crc) {
	startUpdate(0x06);

	insertFloat(posX);
	insertFloat(posZ);
	insertFloat(posY);
	insertLong(0); //?
	insertInt(crc);
}

void MissionObjectDeltaMessage3::updateCreator() {
	startUpdate(0x07);

	insertUnicode(miso->getCreatorName());
}

void MissionObjectDeltaMessage3::updateWaypoint(WaypointObject* way) {
	startUpdate(0x10);

	// Waypoint Info

	way->insertToMessage(this);
	/*
	 * insertInt(0); // ?
	insertFloat(miso->getDestX()); //x
	insertFloat(miso->getDestZ()); //z
	insertFloat(miso->getDestY()); //y
	insertLong(0); //Target ID
	insertInt(miso->getDestPlanetCrc()); //planet crc
	UnicodeString title = "@" + miso->getTitleStf() + ":" + miso->getTitle();
	insertUnicode(title); //Name
	insertLong(miso->getWaypointID()); //waypoint obj id
	insertByte(0x03); //color
	insertByte(0x01); //active*/
}

// Description Key
/*void updateDescKey() {
	startUpdate(0x04);

	insertInt(miso->getDescKey()); //make sure this isnt being reversed! like m27t -> t72m
}

//Title Key
void updateTitleKey() {
	startUpdate(0x04);

	insertInt(miso->getTitleKey()); //make sure this isnt being reversed! like m27t -> t72m
}

void updateDestination() {
	startUpdate(0x06);

	insertFloat(miso->getDestX());
	insertFloat(0.0f);
	insertFloat(miso->getDestY());
	insertLong(0); //?
	insertInt(miso->getDestPlanetCrc());
}

void updateCreator() {
	startUpdate(0x07);

	insertUnicode(miso->getCreatorName());
}

void updateDepictedObject() {
	startUpdate(0x0A);

	insertInt(miso->getDepictedObjCrc());
}*/