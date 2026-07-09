#include "ForceFeedback1Command.h"

ForceFeedback1Command::ForceFeedback1Command(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
	buffCRC = BuffCRC::JEDI_FORCE_FEEDBACK_1;
	blockingCRCs.add(BuffCRC::JEDI_FORCE_FEEDBACK_2);
	singleUseEventTypes.add(ObserverEventType::FORCEFEEDBACK);

	skillMods.put("force_feedback", 65);
}

int ForceFeedback1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	return doJediSelfBuffCommand(creature);
}