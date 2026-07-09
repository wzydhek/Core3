/*
 * PatrolPathNode.h
 *
 *  Created on: 20/01/2012
 *      Author: victor
 */

#pragma once

#include "templates/LuaTemplate.h"
#include "engine/util/u3d/Vector3.h"

class PatrolPathNode : public Object {
	String id, link;
	Vector3 position;
	uint32 cellid;
	String command;
	String arguments;
	uint32 pause;

public:
	PatrolPathNode();

	PatrolPathNode(const PatrolPathNode& node);

	PatrolPathNode& operator=(const PatrolPathNode& node);

	void readObject(LuaObject* luaObject);

	String getArguments() const;

	uint32 getCellid() const;

	String getCommand() const;

	String getId() const;

	Vector3 getPosition() const;

	void setArguments(const String& arguments);

	void setCellid(uint32 cellid);

	void setCommand(const String& command);

	void setId(String id);

	void setPosition(Vector3 position);

};
