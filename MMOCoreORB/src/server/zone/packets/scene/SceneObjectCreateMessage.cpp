#include "SceneObjectCreateMessage.h"

SceneObjectCreateMessage::SceneObjectCreateMessage(const SceneObject* scno) : BaseMessage() {
	insertShort(0x05);
	insertInt(0xFE89DDEA);									   // CRC
	insertLong(const_cast<SceneObject*>(scno)->getObjectID()); // ObjectID
	insertFloat(scno->getDirectionX());
	insertFloat(scno->getDirectionY());
	insertFloat(scno->getDirectionZ());
	insertFloat(scno->getDirectionW());
	/*
			insertFloat(0);
			insertFloat(0);
			insertFloat(0);
			insertFloat(1);
	*/
	insertFloat(scno->getPositionX());
	insertFloat(scno->getPositionZ());
	// scno->info("sending z = " + String::valueOf(scno->getPositionZ()), true);
	insertFloat(scno->getPositionY());
	insertInt(scno->getClientObjectCRC()); // ObjectCRC
	insertByte(const_cast<SceneObject*>(scno)->isHyperspacing() ? 0x01 : 0x00);

	setCompression(true);
}

SceneObjectCreateMessage::SceneObjectCreateMessage(uint64 oid, uint32 objCrc) : BaseMessage() {
	insertShort(0x05);
	insertInt(0xFE89DDEA); // CRC
	insertLong(oid);	   // ObjectID
	insertFloat(0);
	insertFloat(0);
	insertFloat(0);
	insertFloat(0); // was 1
	insertFloat(0);
	insertFloat(0);
	insertFloat(0);
	insertInt(objCrc); // ObjectCRC
	insertByte(0x00);

	setCompression(true);
}

void SceneObjectCreateMessage::parseMessage(Message* pack, SceneObject* scno) {
	pack->shiftOffset(16);

	float x = pack->parseFloat();
	float z = pack->parseFloat();
	float y = pack->parseFloat();

	scno->setPosition(x, z, y);
}