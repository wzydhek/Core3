/*
 * SharedResourceContainerObjectTemplate.h
 *
 *  Created on: 06/05/2010
 *      Author: kyle
 */

#pragma once

#include "templates/SharedTangibleObjectTemplate.h"

class SurveyToolTemplate : public SharedTangibleObjectTemplate {
private:
	int toolType;
	String surveyType;
	String surveyAnimation;
	String sampleAnimation;

public:
	SurveyToolTemplate();

	~SurveyToolTemplate();

	void readObject(LuaObject* templateData) override;

	int getToolType() const;

	const String& getSurveyType() const;

	const String& getSurveyAnimation() const;

	const String& getSampleAnimation() const;
};
