#include "UpdatePVPStatusMessage.h"
#include "templates/params/creature/ObjectFlag.h"

UpdatePVPStatusMessage::UpdatePVPStatusMessage(TangibleObject* tano) : BaseMessage() {
	insertShort(0x04);
	insertInt(0x08A1C126); // UpdatePVPStatusMessage
	insertInt(tano->getPvpStatusBitmask());
	insertInt(tano->getFaction());
	insertLong(tano->getObjectID());
}

UpdatePVPStatusMessage::UpdatePVPStatusMessage(TangibleObject* tano, TangibleObject* receiver, uint32 pvpStatusBitmask) : BaseMessage() {
	insertShort(0x04);
	insertInt(0x08A1C126); // UpdatePVPStatusMessage
	insertInt(pvpStatusBitmask);

	unsigned int faction = 0;
	if (!tano->isPlayerCreature() || tano->getFaction() == receiver->getFaction() || pvpStatusBitmask & ObjectFlag::OVERT) {
		faction = tano->getFaction();
	}

	insertInt(faction);
	insertLong(tano->getObjectID());
}