#include "ForceFeedback2Command.h"

ForceFeedback2Command::ForceFeedback2Command(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_FORCE_FEEDBACK_2;
	overrideableCRCs.add(BuffCRC::JEDI_FORCE_FEEDBACK_1);
	singleUseEventTypes.add(ObserverEventType::FORCEFEEDBACK);
	skillMods.put("force_feedback", 95);
}

int ForceFeedback2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}