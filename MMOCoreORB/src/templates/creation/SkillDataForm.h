/*
 * SkillDataForm.h
 *
 *  Created on: Apr 22, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

class SkillDataForm : public IffTemplate {
	VectorMap<String, String> professionInfoPaths;

public:
	SkillDataForm();

	~SkillDataForm();

	void readObject(IffStream* iffStream);

	int getTotalPaths() const;

	const String& getPathBySkillName(const String& professionName) const;

	const String& getSkillNameAt(int idx) const;
};
