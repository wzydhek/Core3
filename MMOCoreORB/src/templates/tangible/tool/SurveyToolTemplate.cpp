#include "SurveyToolTemplate.h"

SurveyToolTemplate::SurveyToolTemplate() : toolType(0) {
}

SurveyToolTemplate::~SurveyToolTemplate() {
}

void SurveyToolTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	toolType = templateData->getIntField("toolType");
	surveyType = templateData->getStringField("surveyType");
	surveyAnimation = templateData->getStringField("toolAnimation");
	sampleAnimation = templateData->getStringField("sampleAnimation");
}

int SurveyToolTemplate::getToolType() const {
	return toolType;
}

const String& SurveyToolTemplate::getSurveyType() const {
	return surveyType;
}

const String& SurveyToolTemplate::getSurveyAnimation() const {
	return surveyAnimation;
}

const String& SurveyToolTemplate::getSampleAnimation() const {
	return sampleAnimation;
}