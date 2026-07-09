/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class DraftSlot : public Object {
private:

	String stringIdFile;
	String stringIdName;

	// resource name in stf format
	String resourceType;

	// example: 3
	uint32 quantity;

	// example: 2 = Identical items required, 1 = optional, 0 = standard
	int slotType;

	// Contribution level
	float contribution;

public:
	enum {
		RESOURCESLOT,
		IDENTICALSLOT,
		MIXEDSLOT,
		OPTIONALIDENTICALSLOT,
		OPTIONALMIXEDSLOT
	};

public:
	DraftSlot();

	~DraftSlot();

	void insertToMessage(BaseMessage* msg);

    float getContribution() const;
	
	String getStringIdFile() const;
	
	String getStringIdName() const;

    uint32 getQuantity() const;

    String getResourceType() const;

    int getSlotType() const;

    void setContribution(float contribution);

    void setQuantity(uint32 quantity);

    void setResourceType(String resourceType);

    void setSlotType(int slotType);

    void setStringId(String file, String name);
};
