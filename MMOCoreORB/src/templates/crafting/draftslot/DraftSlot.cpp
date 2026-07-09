#include "DraftSlot.h"

DraftSlot::DraftSlot() : quantity(0), slotType(0), contribution(0) {
}

DraftSlot::~DraftSlot() {
}

void DraftSlot::insertToMessage(BaseMessage* msg) {
	msg->insertAscii(stringIdFile); // ex: craft_food_ingredients_n
	msg->insertInt(0);
	msg->insertAscii(stringIdName); // ex: dried_fruit

	if (slotType == OPTIONALIDENTICALSLOT || slotType == OPTIONALMIXEDSLOT)
		msg->insertByte(1); // ex: additive is optional so insertByte(1);
	else
		msg->insertByte(0);

	msg->insertInt(1);

	msg->insertAscii(stringIdFile); // ex: craft_food_ingredients_n
	msg->insertInt(0);
	msg->insertAscii(stringIdName); // ex: dried_fruit

	UnicodeString uniResourceType(resourceType);
	msg->insertUnicode(uniResourceType); // ex: organic

	if (slotType == MIXEDSLOT || slotType == OPTIONALMIXEDSLOT) {
		msg->insertByte(5);		  // Enables Components
		msg->insertInt(quantity); // ex: 3
	} else if (slotType == IDENTICALSLOT || slotType == OPTIONALIDENTICALSLOT) {
		msg->insertByte(2);
		msg->insertInt(quantity); // ex: 3
		msg->insertShort(0);
	} else if (slotType == RESOURCESLOT) {
		msg->insertByte(4);
		msg->insertInt(quantity); // ex: 3
	}
}

float DraftSlot::getContribution() const {
	return contribution;
}

String DraftSlot::getStringIdFile() const {
	return stringIdFile;
}

String DraftSlot::getStringIdName() const {
	return stringIdName;
}

uint32 DraftSlot::getQuantity() const {
	return quantity;
}

String DraftSlot::getResourceType() const {
	return resourceType;
}

int DraftSlot::getSlotType() const {
	return slotType;
}

void DraftSlot::setContribution(float contribution) {
	this->contribution = (contribution / 100.0f);
}

void DraftSlot::setQuantity(uint32 quantity) {
	this->quantity = quantity;
}

void DraftSlot::setResourceType(String resourceType) {
	this->resourceType = resourceType;
}

void DraftSlot::setSlotType(int slotType) {
	this->slotType = slotType;
}

void DraftSlot::setStringId(String file, String name) {
	stringIdFile = file;
	stringIdName = name;
}