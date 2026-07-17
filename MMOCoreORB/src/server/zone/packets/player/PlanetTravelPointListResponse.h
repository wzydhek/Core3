/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class TravelPoint {
	String name;
	
	float positionX;
	float positionY;
	float positionZ;
	
	uint32 tax;
	uint8 starport;
	
public:
	TravelPoint(const String& Name, float x, float z, float y, uint32 tax, uint8 starport);
	
	friend class PlanetTravelPointListResponse;
};

class PlanetTravelPointListResponse : public BaseMessage {
	Vector<TravelPoint*> travelPoints;
	
public:
	PlanetTravelPointListResponse();

	PlanetTravelPointListResponse(const String& planet);
	
	~PlanetTravelPointListResponse();
    
    void addPoint(const String& name, float x, float z, float y, uint32 tax, uint8 starport);
    
    void generateMessage();
    
    void insertNames();
    
    void insertCoords();
    
    void insertTax();
    
    void insertStarport();
	
};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
