
/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/tangible/TangibleObject.h"

class IngredientSlot : public Serializable, public Logger {

protected:

	String slotName;
	String contentType;

	int requiredQuantity;

	bool identical;
	bool optional;

	short clientSlotType;

public:

	enum {
		RESOURCESLOT,
		IDENTICALSLOT,
		MIXEDSLOT,
		OPTIONALIDENTICALSLOT,
		OPTIONALMIXEDSLOT
	};

	// Crafting error messages
	enum {
		OK                       = 0x00,
		NOSERVER                 = 0x01, // No server for Owner
		NOTASSEMBLYSTAGE         = 0x02, // Not in crafting assembly stage
		NOTCUSTOMIZATIONSTAGE    = 0x03, // Not in crafting customization stage
		NOSCHEMATIC              = 0x04, // No Draft Schematic Found
		NOTOOL                   = 0x05, // No Crafting tool Found
		NOMANUFACTURE            = 0x06, // No manufacturing schematic found
		INVALID                  = 0x07, // Invalid Slot Chosen
		INVALIDOPTION            = 0x08, // Invalid Slot Option Chosen
		INVALIDINGREDIENTSIZE    = 0x09, // Invalid ingredient size for slot
		FULL                     = 0x0A, // Slot Full
		INVALIDINGREDIENT        = 0x0B, // Invalid Ingredient
		INGREDIENTNOTININVENTORY = 0x0C, // Ingredient not in inventory
		BADCRATE                 = 0x0D, // Cannot remove resource from crate
		BADRESOURCEFOR           = 0x0E, // Bad resource for Slot
		COMPONENTDAMAGED         = 0x0F, // Component too damaged for use
		NOCOMPONENTTRANSFER      = 0x10, // Cannot transfer componenet
		BADCOMPONENT             = 0x11, // Bad component for slot
		NOINVENTORY              = 0x12, // Inventory Missing
		BADSTATIONHOPPER         = 0x13, // Bad station Hopper
		BADTARGETCONTAINER       = 0x14, // Bad target container
		EMPTYISEMPTY             = 0x15, // Empty slot is empty
		FAILEDRESOURCECREATE     = 0x16, // Cannot create resource container
		EMPTYASSEMBLE            = 0x17, // Trying to assemble with empty slot
		PARTIALASSEMBLE          = 0x18, // Trying to assemble with patially full slot
		PROTOTYPENOTFOUND        = 0x19, // Prototype not found
		BADNAME                  = 0x1A, // Rename object and resend
		MYSTERY                  = 0x1B, // Didn't read this one
		FAILEDTOTRANSFER         = 0x1C, // Failed to transfer resources to station
		WEIRDFAILEDMESSAGE       = 0x1D // Hey nonny nonny tra la la!
	};

public:
	IngredientSlot();

	IngredientSlot(const IngredientSlot& slot);

	~IngredientSlot();

	Object* clone();

	Object* clone(void* object);

	int getClientSlotType();

	void setOptional(bool value);

	bool isOptional();

	void setIdentical(bool value);

	bool requiresIdentical();

	void setContentType(const String& value);

	void setQuantityNeeded(int value);

	int getQuantityNeeded();

	virtual bool add(CreatureObject* player, SceneObject* satchel, ManagedReference<TangibleObject*> tano);

	bool removeAll(CreatureObject* player);

	virtual bool returnToParents(CreatureObject* player);

	void setSlotName(const String& name);

	const String& getSlotName();

	virtual bool isFull();

	virtual bool isEmpty();

	virtual int size();

	virtual void print();

	virtual int getSlotQuantity();

	virtual bool isResourceSlot();

	virtual bool isComponentSlot();

	virtual Vector<uint64> getOIDVector();

	virtual Vector<int> getQuantityVector();

	virtual SceneObject* getFactoryIngredient();


};
