/*
 * ChildObject.h
 *
 *  Created on: 28/07/2010
 *      Author: victor
 */

#pragma once

#include "engine/util/u3d/Quaternion.h"
#include "engine/lua/LuaObject.h"

namespace templates {

class ChildObject : public Object {
protected:
	Vector3 position;
	Quaternion direction;
	String templateFile;
	int cellid;
	int containmentType;
	int componentSlot;

public:
	ChildObject();

	ChildObject(const Vector3 pos, const Quaternion& dir, const String& templateF, int cellID, int contType, int shipCompSlot);

	ChildObject(const ChildObject& obj);

	ChildObject& operator=(const ChildObject& obj);

	void parseFromLua(LuaObject* luaObject);

	void setPosition(float x, float z, float y);

	void setDirection(float fw, float fx, float fy, float fz);

	void setCellId(int id);

	void setContainmentType(int containment);

	void setTemplateFile(const String& file);

	const Vector3& getPosition() const;

	const Quaternion& getDirection() const;

	const String& getTemplateFile() const;

	int getCellId() const;

	int getContainmentType() const;

	int getComponentSlot() const;
};

} // namespace templates

using namespace templates;