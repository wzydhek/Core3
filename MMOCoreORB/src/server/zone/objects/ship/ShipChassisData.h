//
// Created by g on 12/21/17.
//

#pragma once

#include "engine/engine.h"
#include "ComponentSlots.h"
#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class ShipChassisData : public Object {

public:
	class ComponentHardpoint : public Object {
		String templateName;
		String hardpointName;
		float range;
	public:
		ComponentHardpoint(const String& tmpl, const String& hardpoint, float collisionDistance);

		float getRange() const;

		bool isVisible() const;

		const String& getTemplateName() const;

		const String& getHardpointName() const;
	};

	class ComponentSlotData : public Object {
		String name;
		String compatability;
		float hitWeight;
		bool targetable;
		VectorMap<String, Vector<const ComponentHardpoint*>> componentHardpoints;
	public:
		ComponentSlotData(const String& slotName, const String& slotCompatability, float weight, bool isTargetable);

		ComponentSlotData(const ComponentSlotData& rhs);

		const VectorMap<String, Vector<const ComponentHardpoint*>>& getComponentHardpoints() const;

		const Vector<const ComponentHardpoint*>& getHardpoint(const String& name) const;

		void addHardpointData(String componentName, Vector<const ComponentHardpoint*>& hardpoints);

		const String& getName() const;

		const String& getCompatability() const;

		float getHitWeight() const;

		bool isTargetable() const;
	};

protected:
	String name;
	float wingOpenSpeed;
	int type;

	VectorMap<String, ComponentSlotData*> componentMap;
	void loadComponentHardpoints();
public:
	ShipChassisData(DataTableRow *row, Vector<String>& columnNames);

	~ShipChassisData();

	const String& getName() const;

	float getWingOpenSpeed() const;

	const ComponentSlotData* getComponentSlotData(int slotIndex) const;
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
