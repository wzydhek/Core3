/*
 * SharedShipObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"
#include "server/zone/objects/ship/ComponentSlots.h"

namespace templates {
namespace tangible {
namespace ship {

class SharedShipObjectTemplate : public SharedTangibleObjectTemplate {
	StringParam interiorLayoutFileName;
	StringParam cockpitFilename;

	StringParam chassisDataName;
	StringParam chassisTypeName;

	StringParam chassisCategory;
	IntegerParam chassisLevel;

	VectorMap<String, float> attributeMap;

	VectorMap<String, String> componentNames;
	VectorMap<String, VectorMap<String, float>> componentValues;

	BoolParam hasWings;
	BoolParam playerControlled;

	FloatParam chassisHitpoints;
	FloatParam chassisSlipRate;
	FloatParam chassisSpeed;
	FloatParam chassisMass;

	StringParam shipDifficulty;
	StringParam shipFaction;

	VectorMap<String, Vector<Vector3>> sparkLocations;
	VectorMap<String, Vector<Vector3>> launchLocations;
	VectorMap<int, uint32> plasmaConduitTypes;

public:
	SharedShipObjectTemplate();

	~SharedShipObjectTemplate();

	const VectorMap<String, float>& getAttributeMap() const;

	const VectorMap<String, String>& getComponentNames() const;

	const VectorMap<String, VectorMap<String, float>>& getComponentValues() const;

	const VectorMap<String, Vector<Vector3>>& getSparkLocations();

	const VectorMap<String, Vector<Vector3>>& getLaunchLocations();

	const VectorMap<int, uint32>& getPlasmaConduitTypes();

	void readAttributeMap(LuaObject* templateData);

	void readPobData(LuaObject* templateData);

	void readObject(LuaObject* templateData);

	const String& getShipName() const;

	const String& getShipType() const;

	float getChassisHitpoints() const;

	float getChassisSlipRate() const;

	float getChassisSpeed() const;

	float getChassisMass() const;

	bool shipHasWings() const;

	const String& getShipDifficulty() const;

	const String& getShipFaction() const;

	const String& getChassisCategory() const;

	int getChassisLevel() const;

	void parseVariableData(const String& varName, Chunk* data);

	void loadMap(const char** fields, int fieldsLen, VectorMap<String, float>& map, LuaObject& obj);

	void parseFileData(IffStream* iffStream);

	void readObject(IffStream* iffStream);
};

} // namespace ship
} // namespace tangible
} // namespace templates

using namespace templates::tangible::ship;
