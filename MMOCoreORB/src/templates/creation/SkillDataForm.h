/*
 * SkillDataForm.h
 *
 *  Created on: Apr 22, 2011
 *      Author: crush
 */

#pragma once

#include "templates/IffTemplate.h"

namespace templates {
namespace creation {

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

} // namespace creation
} // namespace templates

using namespace templates::creation;
