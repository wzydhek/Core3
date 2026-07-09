#include "IngredientSlot.h"

IngredientSlot::IngredientSlot() {
	requiredQuantity = 0;

	identical = false;
	optional = false;

	clientSlotType = 0;

	setLogging(false);
}

IngredientSlot::IngredientSlot(const IngredientSlot& slot) : Object(), Serializable(), Logger() {
	slotName = slot.slotName;
	requiredQuantity = slot.requiredQuantity;
	identical = slot.identical;
	optional = slot.optional;
	contentType = slot.contentType;

	clientSlotType = slot.clientSlotType;

	setLogging(false);
}

IngredientSlot::~IngredientSlot() {
	// info("Deleting Slot type " + String::valueOf(slottype));
}

Object* IngredientSlot::clone() {
	return ObjectCloner<IngredientSlot>::clone(this);
}

Object* IngredientSlot::clone(void* object) {
	return TransactionalObjectCloner<IngredientSlot>::clone(this);
}

int IngredientSlot::getClientSlotType() {
	return clientSlotType;
}

void IngredientSlot::setOptional(bool value) {
	optional = value;
}

bool IngredientSlot::isOptional() {
	return optional == true;
}

void IngredientSlot::setIdentical(bool value) {
	identical = value;
}

bool IngredientSlot::requiresIdentical() {
	return identical == true;
}

void IngredientSlot::setContentType(const String& value) {
	contentType = value;
}

void IngredientSlot::setQuantityNeeded(int value) {
	requiredQuantity = value;
}

int IngredientSlot::getQuantityNeeded() {
	return requiredQuantity;
}

bool IngredientSlot::add(CreatureObject* player, SceneObject* satchel, ManagedReference<TangibleObject*> tano) {
	return false;
}

bool IngredientSlot::removeAll(CreatureObject* player) {
	return returnToParents(player);
}

bool IngredientSlot::returnToParents(CreatureObject* player) {
	return false;
}

void IngredientSlot::setSlotName(const String& name) {
	slotName = name;
}

const String& IngredientSlot::getSlotName() {
	return slotName;
}

bool IngredientSlot::isFull() {
	return false;
}

bool IngredientSlot::isEmpty() {
	return true;
}

int IngredientSlot::size() {
	return 0;
}

void IngredientSlot::print() {
}

int IngredientSlot::getSlotQuantity() {
	return -1;
}

bool IngredientSlot::isResourceSlot() {
	return false;
}

bool IngredientSlot::isComponentSlot() {
	return false;
}

Vector<uint64> IngredientSlot::getOIDVector() {
	Vector<uint64> oid;
	return oid;
}

Vector<int> IngredientSlot::getQuantityVector() {
	Vector<int> quantities;
	return quantities;
}

SceneObject* IngredientSlot::getFactoryIngredient() {
	return nullptr;
}