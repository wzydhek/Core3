/*
 * SharedBuildingObjectTemplate.h
 *
 *  Created on: 05/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/tangible/SharedStructureObjectTemplate.h"
#include "templates/ChildCreatureObject.h"
#include "templates/building/SignTemplate.h"
#include "server/zone/managers/gcw/SecurityPatrolSpawn.h"

namespace templates {
namespace building {

class SharedBuildingObjectTemplate : public SharedStructureObjectTemplate {
	StringParam terrainModificationFileName;
	StringParam interiorLayoutFileName;

	Vector<ChildCreatureObject> childCreatureObjects;
	int medicalRating;

	ChildObject sign;

	bool publicStructure;

	bool alwaysPublic;

	Vector3 ejectionPoint;

	int factionBaseType;

	float ejectDistance;

	Vector<SignTemplate> shopSigns;

	Vector<SecurityPatrolSpawn> securitySpawns;

public:
	SharedBuildingObjectTemplate();

	~SharedBuildingObjectTemplate();

	void readObject(LuaObject* templateData);
	void readObject(IffStream* iffStream);

	void parseVariableData(const String& varName, LuaObject* templateData);

	void parseVariableData(const String& varName, Chunk* data);
	void parseFileData(IffStream* iffStream);

	virtual bool isSharedBuildingObjectTemplate();

	bool isPublicStructure() const;

	bool isAlwaysPublic() const;

	const ChildObject* getSign() const;

	int getMedicalRating() const;

	int getChildCreatureObjectsSize() const;

	ChildCreatureObject* getChildCreatureObject(int indx);

	const String& getTerrainModificationFile() const;

	const String& getInteriorLayoutFileName() const;

	const Vector3& getEjectionPoint() const;

	int getFactionBaseType() const;

	int getShopSignsSize() const;

	const SignTemplate* getShopSign(int idx) const;

	float getEjectDistance() const;

	int getSecuritySpawnsSize() const;

	const SecurityPatrolSpawn* getSecurityPatrol(int idx) const;
};

} // namespace building
} // namespace templates

using namespace templates::building;
