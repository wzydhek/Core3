#include "SurveyGMinigameSuiCallback.h"

SurveyGMinigameSuiCallback::SurveyGMinigameSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void SurveyGMinigameSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (cancelPressed)
		return;

	if (player->getPosture() > CreaturePosture::CROUCHED) {
		player->sendSystemMessage("@error_message:survey_standing"); // "You must be standing to take a survey or samples.");
		return;
	}

	ManagedReference<SurveySession*> session = player->getActiveSession(SessionFacadeType::SURVEY).castTo<SurveySession*>();
	if (session == nullptr) {
		return;
	}

	if (args->size() < 1)
		return;

	int value = Integer::valueOf(args->get(0).toString());

	session->surveyGnodeMinigame(value);
}