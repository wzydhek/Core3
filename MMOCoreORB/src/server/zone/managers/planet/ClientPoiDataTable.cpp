#include "ClientPoiDataTable.h"

PoiData::PoiData() : x(0), y(0), z(0) {
}

void PoiData::readObject(DataTableRow* row) {
	row->getValue(0, name);
	row->getValue(1, description);
	row->getValue(2, planet);
	row->getValue(4, x);
	row->getValue(5, z);
	row->getValue(6, y);
}

Vector3 PoiData::getPosition() {
	return Vector3(x, y, z);
}

String PoiData::getDescription() const {
	return description;
}

String PoiData::getName() const {
	return name;
}

String PoiData::getPlanet() const {
	return planet;
}

float PoiData::getX() const {
	return x;
}

ClientPoiDataTable::ClientPoiDataTable() {
	pois.setAllowOverwriteInsertPlan();
}

void ClientPoiDataTable::readObject(DataTableIff* dataTable) {
	for (int i = 0; i < dataTable->getTotalRows(); ++i) {
		PoiData* data = new PoiData();
		data->readObject(dataTable->getRow(i));

		Vector<Reference<PoiData*>> vector = pois.get(data->getPlanet());
		vector.add(data);

		pois.put(data->getPlanet(), vector);
	}
}

bool ClientPoiDataTable::containsPlanet(const String& name) {
	return pois.contains(name);
}

const Vector<Reference<PoiData*>>& ClientPoiDataTable::getPois(const String& planetName) {
	return pois.get(planetName);
}

int ClientPoiDataTable::size() {
	int count = 0;

	for (int i = 0; i < pois.size(); ++i)
		count += pois.get(i).size();

	return count;
}