#include "QuestInfo.h"

QuestInfo::QuestInfo() {
	sendSystemMessage = true;
}

String QuestInfo::getQuestName() {
	return questName;
}

String QuestInfo::getQuestParent() {
	return questParent;
}

String QuestInfo::getQuestParameter() {
	return questParameter;
}

String QuestInfo::getJournalSummary() {
	return journalSummary;
}

String QuestInfo::getAttachScript() {
	return attachScript;
}

String QuestInfo::getTaskOnComplete() {
	return taskOnComplete;
}

String QuestInfo::getTaskOnFail() {
	return taskOnFail;
}

String QuestInfo::getQuestTarget() {
	return questTarget;
}

bool QuestInfo::shouldSendSystemMessage() {
	return sendSystemMessage;
}

void QuestInfo::parseDataTableRow(DataTableRow* row) {
	row->getValue(0, questName);
	row->getValue(1, questParent);
	row->getValue(2, attachScript);
	row->getValue(3, journalSummary);
	row->getValue(5, taskOnComplete);
	row->getValue(6, taskOnFail);
	row->getValue(7, questTarget);
	row->getValue(8, questParameter);
	row->getValue(11, sendSystemMessage);
}