/*
 * PlanetTravelPoint.h
 *
 *  Created on: May 13, 2011
 *      Author: crush
 *  Updated on: Sat Oct 15 10:40:05 PDT 2011 by lordkator - Converted to Vector3, arrival/departure and a number of fixes to make travel more stable
 */

#pragma once

#include <atomic>
#include "server/zone/objects/creature/CreatureObject.h"

class PlanetTravelPoint : public Object {
	ManagedWeakReference<CreatureObject*> shuttleObject;

	String pointZone;
	String pointName;
	Vector3 arrivalVector;
	std::atomic<Vector3> departureVector{};
	bool interplanetaryTravelAllowed;
	bool incomingTravelAllowed;
	float landingRange;

public:
	PlanetTravelPoint(const String& zoneName);

	PlanetTravelPoint(const String& zoneName, const String& cityName, Vector3 arrVector, Vector3 departVector, CreatureObject* shuttle, float range);

	PlanetTravelPoint(const PlanetTravelPoint& ptp);

	PlanetTravelPoint& operator=(const PlanetTravelPoint& ptp);

	void readLuaObject(LuaObject* luaObject);

	// Called by the shuttles and transports to set the shuttle object for the nearest travel point
	void setShuttle(CreatureObject* shuttle);

	void setPointName(const String& name);

	const String& getPointZone() const;

	const String& getPointName() const;

	float getArrivalPositionX() const;

	float getArrivalPositionY() const;

	float getArrivalPositionZ() const;

	Vector3 getArrivalPosition() const;

	float getDeparturePositionX() const;

	float getDeparturePositionY() const;

	float getDeparturePositionZ() const;

	Vector3 getDeparturePosition() const;

	float getLandingRange() const;

	/**
	 * Returns true if this point is has the same zone and name that is passed in.
	 */
	bool isPoint(const String& zoneName, const String& name) const;

	/**
	 * Returns true if this location allows interplanetary travel
	 */
	bool isInterplanetary() const;

	/**
	 * Returns true if this location allows incoming travel
	 */
	bool isIncomingAllowed() const;

	/**
	 * Returns true if travel between this point and the passed in point is permitted.
	 * @param arrivalPoint The destination point.
	 */
	bool canTravelTo(const PlanetTravelPoint* arrivalPoint) const;

	ManagedReference<CreatureObject*> getShuttle();

	String toString() const;
};
