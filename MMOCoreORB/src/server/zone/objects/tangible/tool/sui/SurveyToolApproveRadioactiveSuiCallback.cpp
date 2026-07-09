#include "SurveyToolApproveRadioactiveSuiCallback.h"

SurveyToolApproveRadioactiveSuiCallback::SurveyToolApproveRadioactiveSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void SurveyToolApproveRadioactiveSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed)
		return;

	ManagedReference<SurveyTool*> surveyTool = cast<SurveyTool*>(suiBox->getUsingObject().get().get());

	if (surveyTool == nullptr)
		return;

	Locker _lock(surveyTool);
	surveyTool->consentRadioactiveSample(player);
}