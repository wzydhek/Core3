/*
 * SharedCreatureObjectTemplate.cpp
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#include "templates/creature/SharedCreatureObjectTemplate.h"

SharedCreatureObjectTemplate::SharedCreatureObjectTemplate() {
}

SharedCreatureObjectTemplate::~SharedCreatureObjectTemplate() {
}

void SharedCreatureObjectTemplate::parseVariableData(const String& varName, Chunk* data) {
	if (varName == "gender") {
		gender.parse(data);
	} else if (varName == "niche") {
		niche.parse(data);
	} else if (varName == "species") {
		species.parse(data);
	} else if (varName == "race") {
		race.parse(data);
	} else if (varName == "acceleration") {
		acceleration.parse(data);
	} else if (varName == "speed") {
		speed.parse(data);
	} else if (varName == "turnRate") {
		turnRate.parse(data);
	} else if (varName == "animationMapFilename") {
		animationMapFilename.parse(data);
	} else if (varName == "slopeModAngle") {
		slopeModAngle.parse(data);
	} else if (varName == "slopeModPercent") {
		slopeModPercent.parse(data);
	} else if (varName == "waterModPercent") {
		waterModPercent.parse(data);
	} else if (varName == "stepHeight") {
		stepHeight.parse(data);
	} else if (varName == "collisionHeight") {
		collisionHeight.parse(data);
	} else if (varName == "collisionRadius") {
		collisionRadius.parse(data);
	} else if (varName == "movementDatatable") {
		movementDatatable.parse(data);
	} else if (varName == "postureAlignToTerrain") {
		postureAlignToTerrain.parse(data);
	} else if (varName == "swimHeight") {
		swimHeight.parse(data);
	} else if (varName == "warpTolerance") {
		warpTolerance.parse(data);
	} else if (varName == "collisionOffsetX") {
		collisionOffsetX.parse(data);
	} else if (varName == "collisionOffsetZ") {
		collisionOffsetZ.parse(data);
	} else if (varName == "collisionLength") {
		collisionLength.parse(data);
	} else if (varName == "cameraHeight") {
		cameraHeight.parse(data);
	}
}

void SharedCreatureObjectTemplate::parseVariableData(const String& varName, LuaObject* templateData) {
	lua_State* state = templateData->getLuaState();
	if (varName == "gender") {
		gender = Lua::getIntParameter(state);
	} else if (varName == "species") {
		species = Lua::getIntParameter(state);
	} else if (varName == "niche") {
		niche = Lua::getIntParameter(state);
	} else if (varName == "race") {
		race = Lua::getIntParameter(state);
	} else if (varName == "slopeModPercent") {
		slopeModPercent = Lua::getFloatParameter(state);
	} else if (varName == "slopeModAngle") {
		slopeModAngle = Lua::getFloatParameter(state);
	} else if (varName == "swimHeight") {
		swimHeight = Lua::getFloatParameter(state);
	} else if (varName == "waterModPercent") {
		waterModPercent = Lua::getFloatParameter(state);
	} else if (varName == "stepHeight") {
		stepHeight = Lua::getFloatParameter(state);
	} else if (varName == "collisionHeight") {
		collisionHeight = Lua::getFloatParameter(state);
	} else if (varName == "collisionRadius") {
		collisionRadius = Lua::getFloatParameter(state);
	} else if (varName == "warpTolerance") {
		warpTolerance = Lua::getFloatParameter(state);
	} else if (varName == "collisionOffsetX") {
		collisionOffsetX = Lua::getFloatParameter(state);
	} else if (varName == "collisionOffsetZ") {
		collisionOffsetZ = Lua::getFloatParameter(state);
	} else if (varName == "collisionLength") {
		collisionLength = Lua::getFloatParameter(state);
	} else if (varName == "cameraHeight") {
		cameraHeight = Lua::getFloatParameter(state);
	} else if (varName == "animationMapFilename") {
		animationMapFilename = Lua::getStringParameter(state);
	} else if (varName == "movementDatatable") {
		movementDatatable = Lua::getStringParameter(state);
	} else if (varName == "postureAlignToTerrain") {
		LuaObject post(state);

		postureAlignToTerrain.removeAll();

		for (int i = 1; i <= post.getTableSize(); ++i) {
			postureAlignToTerrain.add(post.getIntAt(i));
		}

		post.pop();
	} else if (varName == "turnRate") {
		LuaObject turns(state);

		turnRate.removeAll();

		for (int i = 1; i <= turns.getTableSize(); ++i) {
			turnRate.add(turns.getFloatAt(i));
		}

		turns.pop();
	} else if (varName == "baseHAM") {
		LuaObject hams(state);

		baseHAM.removeAll();

		for (int i = 1; i <= hams.getTableSize(); ++i) {
			baseHAM.add(hams.getIntAt(i));
		}

		hams.pop();
	} else if (varName == "acceleration") {
		LuaObject accel(state);

		acceleration.removeAll();

		for (int i = 1; i <= accel.getTableSize(); ++i) {
			acceleration.add(accel.getFloatAt(i));
		}

		accel.pop();
	} else if (varName == "speed") {
		LuaObject speedTempl(state);

		speed.removeAll();

		for (int i = 1; i <= speedTempl.getTableSize(); ++i) {
			speed.add(speedTempl.getFloatAt(i));
		}

		speedTempl.pop();
	} else {
		templateData->pop();
	}
}

void SharedCreatureObjectTemplate::parseFileData(IffStream* iffStream) {
	iffStream->openChunk('PCNT');

	int variableCount = iffStream->getInt();

	iffStream->closeChunk('PCNT');

	for (int i = 0; i < variableCount; ++i) {
	//while (iffStream->getRemainingSubChunksNumber() > 0) {
		Chunk* chunk = iffStream->openChunk('XXXX');

		if (chunk == nullptr)
			continue;

		String varName;
		iffStream->getString(varName);

		//std::cout << "parsing wtf shit:[" << varName.toStdString() << "]\n";
		parseVariableData(varName, chunk);

		iffStream->closeChunk();
	}
}


void SharedCreatureObjectTemplate::readObject(IffStream* iffStream) {
	uint32 nextType = iffStream->getNextFormType();

	if (nextType != 'SCOT') {
		//Logger::console.error("expecting SHOT got " + String::hexvalueOf((int)nextType));

		SharedTangibleObjectTemplate::readObject(iffStream);

		return;
	}

	iffStream->openForm('SCOT');

	uint32 derv = iffStream->getNextFormType();

	if (derv == 'DERV') {
		loadDerv(iffStream);

		derv = iffStream->getNextFormType();
	}

	iffStream->openForm(derv);

	try {
		parseFileData(iffStream);
	} catch (Exception& e) {
		String msg;
		msg += "exception caught parsing file data ->";
		msg += e.getMessage();

		Logger::console.error(msg);
	}

	iffStream->closeForm(derv);

	if (iffStream->getRemainingSubChunksNumber() > 0) {
		readObject(iffStream);
	}

	iffStream->closeForm('SCOT');
}

void SharedCreatureObjectTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	lua_State* L = templateData->getLuaState();

	if (!templateData->isValidTable())
		return;

	int i = 0;

	lua_pushnil(L);
	while (lua_next(L, -2) != 0) {
		// 'key' is at index -2 and 'value' at index -1
		//printf("%s - %s\n",
		//		lua_tostring(L, -2), lua_typename(L, lua_type(L, -1)));

		int type = lua_type(L, -2);

		if (type == LUA_TSTRING) {
			size_t len = 0;
			const char* varName = lua_tolstring(L, -2, &len);

			parseVariableData(varName, templateData);
		} else
			lua_pop(L, 1);


		++i;
	}

	return;

	/*gender = templateData->getIntField("gender");
	species = templateData->getIntField("species");
	niche = templateData->getIntField("niche");
	race = templateData->getIntField("race");
	slopeModPercent = templateData->getFloatField("slopeModPercent");
	slopeModAngle = templateData->getFloatField("slopeModAngle");
	swimHeight = templateData->getFloatField("swimHeight");
	waterModPercent = templateData->getFloatField("waterModPercent");
	stepHeight = templateData->getFloatField("stepHeight");
	collisionHeight = templateData->getFloatField("collisionHeight");
	collisionRadius = templateData->getFloatField("collisionRadius");
	warpTolerance = templateData->getFloatField("warpTolerance");
	collisionOffsetX = templateData->getFloatField("collisionOffsetX");
	collisionOffsetZ = templateData->getFloatField("collisionOffsetZ");
	collisionLength = templateData->getFloatField("collisionLength");
	cameraHeight = templateData->getFloatField("cameraHeight");

	animationMapFilename = templateData->getStringField("animationMapFilename");
	movementDatatable = templateData->getStringField("movementDatatable");

	LuaObject post = templateData->getObjectField("postureAlignToTerrain");

	for (int i = 1; i <= post.getTableSize(); ++i) {
		postureAlignToTerrain.add(post.getIntAt(i));
	}

	post.pop();

	LuaObject turns = templateData->getObjectField("turnRate");

	for (int i = 1; i <= turns.getTableSize(); ++i) {
		turnRate.add(turns.getFloatAt(i));
	}

	turns.pop();

	LuaObject hams = templateData->getObjectField("baseHAM");

	for (int i = 1; i <= hams.getTableSize(); ++i) {
		baseHAM.add(hams.getIntAt(i));
	}

	hams.pop();

	LuaObject accel = templateData->getObjectField("acceleration");

	for (int i = 1; i <= accel.getTableSize(); ++i) {
		acceleration.add(accel.getFloatAt(i));
	}

	accel.pop();

	LuaObject speedTempl = templateData->getObjectField("speed");

	for (int i = 1; i <= speedTempl.getTableSize(); ++i) {
		speed.add(speedTempl.getFloatAt(i));
	}

	speedTempl.pop();*/

}

const Vector<FloatParam>& SharedCreatureObjectTemplate::getAcceleration() const {
	return acceleration.get();
}

const String& SharedCreatureObjectTemplate::getAnimationMapFilename() const {
	return animationMapFilename.getValue();
}

const Vector<int>& SharedCreatureObjectTemplate::getBaseHAM() const {
	return baseHAM;
}

float SharedCreatureObjectTemplate::getCameraHeight() const {
	return cameraHeight;
}

float SharedCreatureObjectTemplate::getCollisionHeight() const {
	return collisionHeight;
}

float SharedCreatureObjectTemplate::getCollisionLength() const {
	return collisionLength;
}

float SharedCreatureObjectTemplate::getCollisionOffsetX() const {
	return collisionOffsetX;
}

float SharedCreatureObjectTemplate::getCollisionOffsetZ() const {
	return collisionOffsetZ;
}

float SharedCreatureObjectTemplate::getCollisionRadius() const {
	return collisionRadius;
}

int SharedCreatureObjectTemplate::getGender() const {
	return gender;
}

const String& SharedCreatureObjectTemplate::getMovementDatatable() const {
	return movementDatatable.getValue();
}

int SharedCreatureObjectTemplate::getNiche() const {
	return niche;
}

const Vector<BoolParam>& SharedCreatureObjectTemplate::getPostureAlignToTerrain() const {
	return postureAlignToTerrain.get();
}

int SharedCreatureObjectTemplate::getRace() const {
	return race;
}

float SharedCreatureObjectTemplate::getSlopeModAngle() const {
	return slopeModAngle;
}

float SharedCreatureObjectTemplate::getSlopeModPercent() const {
	return slopeModPercent;
}

int SharedCreatureObjectTemplate::getSpecies() const {
	return species;
}

const Vector<FloatParam>& SharedCreatureObjectTemplate::getSpeed() const {
	return speed.get();
}

float SharedCreatureObjectTemplate::getStepHeight() const {
	return stepHeight;
}

float SharedCreatureObjectTemplate::getSwimHeight() const {
	return swimHeight;
}

const Vector<FloatParam>& SharedCreatureObjectTemplate::getTurnRate() const {
	return turnRate.get();
}

float SharedCreatureObjectTemplate::getWarpTolerance() const {
	return warpTolerance;
}

float SharedCreatureObjectTemplate::getWaterModPercent() const {
	return waterModPercent;
}

/*void setAcceleration(Vector<float> acceleration) {
	this->acceleration = acceleration;
}*/

void SharedCreatureObjectTemplate::setAnimationMapFilename(String animationMapFilename) {
	this->animationMapFilename = animationMapFilename;
}

void SharedCreatureObjectTemplate::setBaseHAM(Vector<int> baseHAM) {
	this->baseHAM = baseHAM;
}

void SharedCreatureObjectTemplate::setCameraHeight(float cameraHeight) {
	this->cameraHeight = cameraHeight;
}

void SharedCreatureObjectTemplate::setCollisionHeight(float collisionHeight) {
	this->collisionHeight = collisionHeight;
}

void SharedCreatureObjectTemplate::setCollisionLength(float collisionLength) {
	this->collisionLength = collisionLength;
}

void SharedCreatureObjectTemplate::setCollisionOffsetX(float collisionOffsetX) {
	this->collisionOffsetX = collisionOffsetX;
}

void SharedCreatureObjectTemplate::setCollisionOffsetZ(float collisionOffsetZ) {
	this->collisionOffsetZ = collisionOffsetZ;
}

void SharedCreatureObjectTemplate::setCollisionRadius(float collisionRadius) {
	this->collisionRadius = collisionRadius;
}

void SharedCreatureObjectTemplate::setGender(int gender) {
	this->gender = gender;
}

void SharedCreatureObjectTemplate::setMovementDatatable(String movementDatatable) {
	this->movementDatatable = movementDatatable;
}

void SharedCreatureObjectTemplate::setNiche(int niche) {
	this->niche = niche;
}

/*void setPostureAlignToTerrain(Vector<bool> postureAlignToTerrain) {
	this->postureAlignToTerrain = postureAlignToTerrain;
}*/

void SharedCreatureObjectTemplate::setRace(int race) {
	this->race = race;
}

void SharedCreatureObjectTemplate::setSlopeModAngle(float slopeModAngle) {
	this->slopeModAngle = slopeModAngle;
}

void SharedCreatureObjectTemplate::setSlopeModPercent(float slopeModPercent) {
	this->slopeModPercent = slopeModPercent;
}

void SharedCreatureObjectTemplate::setSpecies(int species) {
	this->species = species;
}

/*void setSpeed(Vector<float> speed) {
	this->speed = speed;
}*/

void SharedCreatureObjectTemplate::setStepHeight(float stepHeight) {
	this->stepHeight = stepHeight;
}

void SharedCreatureObjectTemplate::setSwimHeight(float swimHeight) {
	this->swimHeight = swimHeight;
}

/*void setTurnRate(Vector<float> turnRate) {
	this->turnRate = turnRate;
}*/

void SharedCreatureObjectTemplate::setWarpTolerance(float warpTolerance) {
	this->warpTolerance = warpTolerance;
}

void SharedCreatureObjectTemplate::setWaterModPercent(float waterModPercent) {
	this->waterModPercent = waterModPercent;
}