#pragma once

#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class QuestInfo : public Object {

protected:
	String questName, questParent, journalSummary, questParameter, questTarget;
	String attachScript, taskOnComplete, taskOnFail;
	bool sendSystemMessage;

public:
	QuestInfo();

	String getQuestName();

	String getQuestParent();

	String getQuestParameter();

	String getJournalSummary();

	String getAttachScript();

	String getTaskOnComplete();

	String getTaskOnFail();

	String getQuestTarget();

	bool shouldSendSystemMessage();

	void parseDataTableRow(DataTableRow* row);
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;
