/*
 * ClientPoiDataTable.h
 *
 *  Created on: 02/04/2012
 *      Author: victor
 */

#pragma once

#include "templates/datatables/DataTableIff.h"
#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace managers {
namespace planet {

class PoiData : public Object {
protected:
	String name;
	String description;
	String planet;
	float x, y, z;

public:
	PoiData();

	void readObject(DataTableRow* row);

	Vector3 getPosition();

	String getDescription() const;

	String getName() const;

	String getPlanet() const;

	float getX() const;
};

class ClientPoiDataTable : public Object {
	VectorMap<String, Vector<Reference<PoiData*> > > pois;
public:
	ClientPoiDataTable();

	void readObject(DataTableIff* dataTable);

	bool containsPlanet(const String& name);

	const Vector<Reference<PoiData*>>& getPois(const String& planetName);

	int size();
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;
