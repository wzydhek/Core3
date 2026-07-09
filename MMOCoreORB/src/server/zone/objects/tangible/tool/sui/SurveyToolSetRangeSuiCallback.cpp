#include "SurveyToolSetRangeSuiCallback.h"

SurveyToolSetRangeSuiCallback::SurveyToolSetRangeSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void SurveyToolSetRangeSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed)
		return;

	if (args->size() < 1)
		return;

	ManagedReference<SurveyTool*> surveyTool = cast<SurveyTool*>(suiBox->getUsingObject().get().get());

	if (surveyTool == nullptr)
		return;

	int range = 64 * Integer::valueOf(args->get(0).toString()) + 64;

	Locker _lock(surveyTool);
	surveyTool->setRange(range);
}