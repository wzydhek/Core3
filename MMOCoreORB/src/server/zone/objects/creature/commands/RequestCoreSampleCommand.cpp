#include "RequestCoreSampleCommand.h"
#include "server/zone/objects/tangible/tool/SurveyTool.h"
#include "server/zone/objects/player/sessions/survey/SurveySession.h"

RequestCoreSampleCommand::RequestCoreSampleCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int RequestCoreSampleCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature)) {
		creature->sendSystemMessage("@error_message:survey_standing");
		return INVALIDLOCOMOTION;
	}

	// We don't do anything if for some reason it isn't a player
	if (creature->isPlayerCreature()) {
		Reference<Task*> sampletask = creature->getPendingTask("sample");
		Reference<Task*> surveytask = creature->getPendingTask("survey");

		// If the sample task exists, we can't sample again
		if (sampletask != nullptr) {
			AtomicTime nextExecutionTime;
			Core::getTaskManager()->getNextExecutionTime(sampletask, nextExecutionTime);

			uint64 milliNow = Time().getMiliTime();
			uint64 nextExecution = nextExecutionTime.getMiliTime();
			int64 diffCalc = (nextExecution - milliNow);

			if (diffCalc < 0)
				diffCalc = 500;

			int seconds = (int)(diffCalc / 1000);

			StringIdChatParameter message("survey", "tool_recharge_time");
			message.setDI(seconds);
			creature->sendSystemMessage(message);

			return SUCCESS;
		}

		// If the survey task exists, we can't sample
		if (surveytask != nullptr) {
			creature->sendSystemMessage("@survey:sample_survey");

			return SUCCESS;
		}

		ManagedReference<SurveySession*> session = creature->getActiveSession(SessionFacadeType::SURVEY).castTo<SurveySession*>();

		if (session == nullptr) {
			creature->sendSystemMessage("@ui:survey_notool");
			return GENERALERROR;
		}

		session->setActiveSurveyTool(session->getOpenSurveyTool().get());
		session->startSample(arguments.toString());
	}

	return SUCCESS;
}