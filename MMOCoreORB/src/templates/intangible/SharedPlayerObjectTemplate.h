/*
 * SharedPlayerObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: victor
 */

#pragma once

#include "templates/SharedIntangibleObjectTemplate.h"

class SharedPlayerObjectTemplate : public SharedIntangibleObjectTemplate {
protected:
	SortedVector<String> playerDefaultGroupPermissions;

public:
	SharedPlayerObjectTemplate();

	~SharedPlayerObjectTemplate();

	void readObject(IffStream* iffStream);

	void readObject(LuaObject* templateData);

	void parseVariableData(const String& varName, LuaObject* templateData);

	const SortedVector<String>* getPlayerDefaultGroupPermissions() const;

};
