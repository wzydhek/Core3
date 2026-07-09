/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "templates/crafting/AttributesMap.h"
#include "engine/engine.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace manufactureschematic {

   class ManufactureSchematic;
}
}
}
}

using namespace server::zone::objects::manufactureschematic;

namespace server {
 namespace zone {
  namespace objects {
   namespace creature {

   class CreatureObject;
}
}
}
}

using namespace server::zone::objects::creature;

namespace server {
 namespace zone {
  namespace objects {
   namespace manufactureschematic {
   	 namespace craftingvalues {


class CraftingValues : public Serializable, public Logger {
	AttributesMap attributesMap;

	Vector<String> valuesToSend;

	bool doHide;

	ManagedWeakReference<ManufactureSchematic*> schematic;
	ManagedWeakReference<CreatureObject*> player;
	VectorMap<String, bool> slots;

public:

	enum {
		NORMAL = 1,
		HIDDEN = 2
	};

public:
	CraftingValues();
	CraftingValues(const CraftingValues& values);
	CraftingValues(const AttributesMap& map);

	~CraftingValues();

	void setManufactureSchematic(ManufactureSchematic* manu);
	ManufactureSchematic* getManufactureSchematic();
	void setPlayer(CreatureObject* play);
	CreatureObject* getPlayer();

	// new Implementation of AttributesMap
	void addExperimentalAttribute(const String& attribute, const String& group, const float min, const float max, const int precision, const bool filler, const int combine);

	const String& getAttribute(const int i) const;

	const String& getAttributeGroup(const String& attribute) const;

	const String& getVisibleAttributeGroup(const int i) const;

	int getTotalExperimentalAttributes() const;

	bool hasExperimentalAttribute(const String& attribute) const;

	bool isHidden(const String& attribute) const;

	void setHidden(const String& attribute);

	void unsetHidden(const String& attribute);

	short getCombineType(const String& attribute) const;

	void setCurrentValue(const String& attribute, const float value);

	void setCurrentValue(const String& attribute, const float value, const float min, const float max);

	float getCurrentValue(const String& attribute) const;

	float getCurrentValue(const int i) const;

	void lockValue(const String& attribute);

	void unlockValue(const String& attribute);

	void resetValue(const String& attribute);

	void setCurrentPercentage(const String& subtitle, const float value);

	void setCurrentPercentage(const String& subtitle, const float value, const float max);

	float getCurrentPercentage(const String& attribute) const;

	float getCurrentPercentage(const int i) const;

	float getCurrentVisiblePercentage(const String title) const;

	void setMaxPercentage(const String& attribute, const float value);

	float getMaxPercentage(const String& attribute) const;

	float getMaxPercentage(const int i) const;

	float getMaxVisiblePercentage(const int i) const;

	float getMinValue(const String& attribute) const;

	float getMaxValue(const String& attribute) const;

	float getCapValue(const String& attribute) const;

	void setMinValue(const String& attribute, const float value);

	void setMaxValue(const String& attribute, const float value);

	void setCapValue(const String& attribute, const float value);

	int getPrecision(const String& attribute) const;

	void setPrecision(const String& attribute, const int precision);

	int getTotalVisibleAttributeGroups() const;

	void recalculateValues(bool initial);

	String toString() const;

	void setSlot(const String& value, bool filled);

	void clearSlots();

	bool hasSlotFilled(const String& name) const;

	void addValueToSend(const String& name);

	int getValuesToSendSize() const;

	const String& getValuesToSend(const int i) const;

	float getAttributeAndValue(const String& attribute, const int i) const;

	// Clear
	void clear();

	void clearAll();
};

}
}
}
}
}

using namespace server::zone::objects::manufactureschematic::craftingvalues;
