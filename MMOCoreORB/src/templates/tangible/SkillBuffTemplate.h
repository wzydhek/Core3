/*
 * SkillBuffTemplate.h
 *
 *  Created on: 9/21/2013
 *      Author: Klivian
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

namespace templates {
namespace tangible {

class SkillBuffTemplate : public SharedTangibleObjectTemplate {
	int duration;
	VectorMap<String, float> modifiers;
	String buffName;
	unsigned int buffCRC;

public:
	SkillBuffTemplate();

	~SkillBuffTemplate();

	void readObject(LuaObject* templateData);

    String& getBuffName();

    int getDuration() const;

	VectorMap<String, float>* getModifiers();

	bool isSkillBuffTemplate();

	unsigned int getBuffCRC();

};

} // namespace tangible
} // namespace templates

using namespace templates::tangible;
