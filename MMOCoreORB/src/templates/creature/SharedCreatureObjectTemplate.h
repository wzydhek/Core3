/*
 * SharedCreatureObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"
#include "templates/params/VectorParam.h"

#include "engine/lua/Lua.h"

namespace templates {
namespace creature {

class SharedCreatureObjectTemplate: public SharedTangibleObjectTemplate {
protected:
	IntegerParam gender;
	IntegerParam niche;
	IntegerParam species;
	IntegerParam race;

	VectorParam<FloatParam> acceleration;
	VectorParam<FloatParam> speed;
	VectorParam<FloatParam> turnRate;

	StringParam animationMapFilename;

	FloatParam slopeModAngle;
	FloatParam slopeModPercent;
	FloatParam waterModPercent;
	FloatParam stepHeight;
	FloatParam collisionHeight;
	FloatParam collisionRadius;

	StringParam movementDatatable;

	VectorParam<BoolParam> postureAlignToTerrain;

	FloatParam swimHeight;
	FloatParam warpTolerance;
	FloatParam collisionOffsetX;
	FloatParam collisionOffsetZ;
	FloatParam collisionLength;
	FloatParam cameraHeight;

	Vector<int> baseHAM;

public:
	SharedCreatureObjectTemplate();

	~SharedCreatureObjectTemplate();

	void readObject(LuaObject* templateData);
	void readObject(IffStream* iffStream);

	void parseVariableData(const String& varName, LuaObject* templateData);

	void parseVariableData(const String& varName, Chunk* data);
	void parseFileData(IffStream* iffStream);

	const Vector<FloatParam>& getAcceleration() const;

	const String& getAnimationMapFilename() const;

	const Vector<int>& getBaseHAM() const;

	float getCameraHeight() const;

	float getCollisionHeight() const;

	float getCollisionLength() const;

	float getCollisionOffsetX() const;

	float getCollisionOffsetZ() const;

	float getCollisionRadius() const;

	int getGender() const;

	const String& getMovementDatatable() const;

	int getNiche() const;

	const Vector<BoolParam>& getPostureAlignToTerrain() const;

	int getRace() const;

	float getSlopeModAngle() const;

	float getSlopeModPercent() const;

	int getSpecies() const;

	const Vector<FloatParam>& getSpeed() const;

	float getStepHeight() const;

	float getSwimHeight() const;

	const Vector<FloatParam>& getTurnRate() const;

	float getWarpTolerance() const;

	float getWaterModPercent() const;

	void setAnimationMapFilename(String animationMapFilename);

	void setBaseHAM(Vector<int> baseHAM);

	void setCameraHeight(float cameraHeight);

	void setCollisionHeight(float collisionHeight);

	void setCollisionLength(float collisionLength);

	void setCollisionOffsetX(float collisionOffsetX);

	void setCollisionOffsetZ(float collisionOffsetZ);

	void setCollisionRadius(float collisionRadius);

	void setGender(int gender);

	void setMovementDatatable(String movementDatatable);

	void setNiche(int niche);
	
	void setRace(int race);

	void setSlopeModAngle(float slopeModAngle);

	void setSlopeModPercent(float slopeModPercent);

	void setSpecies(int species);

	void setStepHeight(float stepHeight);

	void setSwimHeight(float swimHeight);

	void setWarpTolerance(float warpTolerance);

	void setWaterModPercent(float waterModPercent);

};

} // namespace creature
} // namespace templates

using namespace templates::creature;
