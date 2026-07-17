/*
 * ShipComponent.h
 *
 *  Created on: 18/10/2013
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace objects {
namespace ship {

class ShipComponentData : public Object {
protected:
	String name;
	String objectTemplate;
	String sharedObjectTemplate;
	String componentType;
	String compatibility;
public:
	ShipComponentData();

	void readObject(DataTableRow* row);

	const String& getCompatibility() const;

	const String& getComponentType() const;

	const String& getName() const;

	const String& getObjectTemplate() const;

	const String& getSharedObjectTemplate() const;
};

} // namespace ship
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::ship;
