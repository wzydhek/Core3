#include "ShipUpdateTransformMessage.h"
#include "PackedPosition.h"

ShipUpdateTransformMessage::ShipUpdateTransformMessage(ShipObject* ship, uint32 syncStamp) : BaseMessage(50) {
	insertShort(0x08);	   // Opcode
	insertInt(0x76026fb9); // Message
	insertShort(ship->getUniqueID());

	writePackedDirection(ship->getDirection());
	writePackedPosition(ship->getPosition());

	insertShort(0);
	insertShort(0);

	insertSignedByte(0);
	insertSignedByte(0);
	insertSignedByte(0);

	insertInt(syncStamp ? syncStamp : ship->getSyncStamp());
}

ShipUpdateTransformMessage::ShipUpdateTransformMessage(ShipObject* ship, PackedVelocity& velocity, PackedRotationRate& rA, PackedRotationRate& rB, PackedRotationRate& rC, uint32 syncStamp) : BaseMessage(50) {
	insertShort(0x08);	   // Opcode
	insertInt(0x76026fb9); // Message
	insertShort(ship->getUniqueID());

	writePackedDirection(ship->getDirection());
	writePackedPosition(ship->getPosition());

	velocity.write(this);

	rA.write(this);
	rB.write(this);
	rC.write(this);

	insertInt(syncStamp ? syncStamp : ship->getSyncStamp());
}

ShipUpdateTransformMessage::ShipUpdateTransformMessage(ShipObject* ship, const Vector3& position, PackedVelocity& velocity, PackedRotationRate& rA, PackedRotationRate& rB, PackedRotationRate& rC, uint32 syncStamp) : BaseMessage(50) {
	insertShort(0x08);	   // Opcode
	insertInt(0x76026fb9); // Message
	insertShort(ship->getUniqueID());

	writePackedDirection(ship->getDirection());
	writePackedPosition(position);

	velocity.write(this);

	rA.write(this);
	rB.write(this);
	rC.write(this);

	insertInt(syncStamp ? syncStamp : ship->getSyncStamp());
}

ShipUpdateTransformMessage::ShipUpdateTransformMessage(ShipObject* ship, const Quaternion* direction, const Vector3& position, PackedVelocity& velocity, PackedRotationRate& rA, PackedRotationRate& rB, PackedRotationRate& rC, uint32 syncStamp) : BaseMessage(50) {
	insertShort(0x08);	   // opcode
	insertInt(0x76026fb9); // Message
	insertShort(ship->getUniqueID());

	writePackedDirection(direction);
	writePackedPosition(position);

	velocity.write(this);

	rA.write(this);
	rB.write(this);
	rC.write(this);

	insertInt(syncStamp ? syncStamp : ship->getSyncStamp());
}

ShipUpdateTransformMessage::ShipUpdateTransformMessage(ShipObject* ship, const Vector3& position, PackedVelocity& velocity, uint32 syncStamp) : BaseMessage(50) {
	insertShort(0x08);	   // Opcode
	insertInt(0x76026fb9); // Message
	insertShort(ship->getUniqueID());

	writePackedDirection(ship->getDirection());
	writePackedPosition(position);

	velocity.write(this);

	insertSignedByte(0);
	insertSignedByte(0);
	insertSignedByte(0);

	insertInt(syncStamp ? syncStamp : ship->getSyncStamp());
}

void ShipUpdateTransformMessage::writePackedPosition(const Vector3& position) {
	PackedPosition packed;
	packed.set(position);
	packed.write(this);
}

void ShipUpdateTransformMessage::writePackedDirection(const Quaternion* direction) {
	insertSignedByte((int8)(direction->getW() * 127.f));
	insertSignedByte((int8)(direction->getX() * 127.f));
	insertSignedByte((int8)(direction->getY() * 127.f));
	insertSignedByte((int8)(direction->getZ() * 127.f));
}