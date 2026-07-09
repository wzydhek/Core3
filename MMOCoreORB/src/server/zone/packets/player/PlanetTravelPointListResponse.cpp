#include "PlanetTravelPointListResponse.h"

TravelPoint::TravelPoint(const String& Name, float x, float z, float y, uint32 tax, uint8 starport) {
	name = Name;

	positionX = x;
	positionY = y;
	positionZ = z;

	this->tax = tax;
	this->starport = starport;
}

PlanetTravelPointListResponse::PlanetTravelPointListResponse() : BaseMessage() {
	insertShort(0x06);
	insertInt(0x4D32541F); // PlanetTravelPointListResponse

	insertAscii("naboo");
}

PlanetTravelPointListResponse::PlanetTravelPointListResponse(const String& planet) : BaseMessage() {
	insertShort(0x06);
	insertInt(0x4D32541F); // PlanetTravelPointListResponse
	insertAscii(planet);

	setCompression(true);
}

PlanetTravelPointListResponse::~PlanetTravelPointListResponse() {
	while (travelPoints.size() > 0) {
		TravelPoint* point = travelPoints.remove(0);

		delete point;
	}
}

void PlanetTravelPointListResponse::addPoint(const String& name, float x, float z, float y, uint32 tax, uint8 starport) {
	travelPoints.add(new TravelPoint(name, x, z, y, tax, starport));
}

void PlanetTravelPointListResponse::generateMessage() {
	insertNames();
	insertCoords();
	insertTax();
	insertStarport();
}

void PlanetTravelPointListResponse::insertNames() {
	insertInt(travelPoints.size());

	for (int i = 0; i < travelPoints.size(); ++i) {
		TravelPoint* point = travelPoints.get(i);

		insertAscii(point->name);
	}
}

void PlanetTravelPointListResponse::insertCoords() {
	insertInt(travelPoints.size());

	for (int i = 0; i < travelPoints.size(); ++i) {
		TravelPoint* point = travelPoints.get(i);

		insertFloat(point->positionX);
		insertFloat(point->positionZ);
		insertFloat(point->positionY);
	}
}

void PlanetTravelPointListResponse::insertTax() {
	insertInt(travelPoints.size());

	for (int i = 0; i < travelPoints.size(); ++i) {
		TravelPoint* point = travelPoints.get(i);

		insertInt(point->tax);
	}
}

void PlanetTravelPointListResponse::insertStarport() {
	insertInt(travelPoints.size());

	for (int i = 0; i < travelPoints.size(); ++i) {
		TravelPoint* point = travelPoints.get(i);

		insertByte(point->starport);
	}
}