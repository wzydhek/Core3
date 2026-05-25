/*
 * DroidCustomKitTemplate.h
 *
 *  Created on: 11/29/2013
 *      Author: Klivian
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class DroidCustomKitTemplate : public SharedTangibleObjectTemplate {

public:
	DroidCustomKitTemplate() {

	}

	~DroidCustomKitTemplate() {

	}

	void readObject(LuaObject* templateData) {
		SharedTangibleObjectTemplate::readObject(templateData);

    }

	bool isDroidCustomKitTemplate() {
		return true;
	}

};
