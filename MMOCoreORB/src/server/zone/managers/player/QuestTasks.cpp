#include "QuestTasks.h"

UnknownDatatableException::UnknownDatatableException() : Exception() {
}

UnknownDatatableException::UnknownDatatableException(const String& msg) : Exception(msg) {
}

QuestTask::QuestTask() {
	isVisible = true;
	showSystemMessages = false;
	allowRepeats = false;
	experienceAmount = 0;
	factionAmount = 0;
	bankCredits = 0;
	locationX = 0;
	locationY = 0;
	locationZ = 0;
	radius = 0;
	minTime = 0;
	maxTime = 0;
	count = 0;
	minDistance = 0;
	maxDistance = 0;
	rewardCredits = 0;
	lootItemsRequired = 0;
	lootDropPercent = 0;
}

void QuestTask::parseDataTableRow(const DataTableRow* row, const DataTableIff& dTable) {
	int columnCount = dTable.getTotalColumns();
	for (int i = 0; i < columnCount; i++) {
		String columnName = dTable.getColumnNameByIndex(i);
		if (columnName == "PREREQUISITE_TASKS") {
			String temp;
			row->getValue(i, temp);
			while (temp.contains(",")) {
				auto next = temp.subString(0, temp.indexOf(","));
				prerequisiteTasks.add(Integer::valueOf(next));
				temp = temp.subString(temp.indexOf(",") + 1);
			}
			if (temp != "") {
				prerequisiteTasks.add(Integer::valueOf(temp));
			}
		} else if (columnName == "EXCLUSION_TASKS") {
			String temp;
			row->getValue(i, temp);
			while (temp.contains(",")) {
				auto next = temp.subString(0, temp.indexOf(","));
				exclusionTasks.add(Integer::valueOf(next));
				temp = temp.subString(temp.indexOf(",") + 1);
			}
			if (temp != "") {
				exclusionTasks.add(Integer::valueOf(temp));
			}
		} else if (columnName == "ATTACH_SCRIPT") {
			row->getValue(i, attachScript);
		} else if (columnName == "JOURNAL_ENTRY_TITLE") {
			row->getValue(i, journalEntryTitle);
		} else if (columnName == "JOURNAL_ENTRY_DESCRIPTION") {
			row->getValue(i, journalEntryDescription);
		} else if (columnName == "TASKS_ON_COMPLETE") {
			String temp;
			row->getValue(i, temp);
			while (temp.contains(",")) {
				auto next = temp.subString(0, temp.indexOf(","));
				tasksOnComplete.add(Integer::valueOf(next));
				temp = temp.subString(temp.indexOf(",") + 1);
			}
			if (temp != "") {
				tasksOnComplete.add(Integer::valueOf(temp));
			}
		} else if (columnName == "TASKS_ON_FAIL") {
			String temp;
			row->getValue(i, temp);
			while (temp.contains(",")) {
				auto next = temp.subString(0, temp.indexOf(","));
				tasksOnFail.add(Integer::valueOf(next));
				temp = temp.subString(temp.indexOf(",") + 1);
			}
			if (temp != "") {
				tasksOnFail.add(Integer::valueOf(temp));
			}
		} else if (columnName == "TASK_NAME") {
			row->getValue(i, taskName);
		} else if (columnName == "IS_VISIBLE") {
			row->getValue(i, isVisible);
		} else if (columnName == "SHOW_SYSTEM_MESSAGES") {
			row->getValue(i, showSystemMessages);
		} else if (columnName == "ALLOW_REPEATS") {
			row->getValue(i, allowRepeats);
		} else if (columnName == "MUSIC_ON_ACTIVATE") {
			row->getValue(i, musicOnActivate);
		} else if (columnName == "TARGET") {
			row->getValue(i, target);
		} else if (columnName == "PARAMETER") {
			row->getValue(i, parameter);
		} else if (columnName == "GRANT_QUEST_ON_COMPLETE") {
			row->getValue(i, grantQuestOnComplete);
		} else if (columnName == "GRANT_QUEST_ON_FAIL") {
			row->getValue(i, grantQuestOnFail);
		} else if (columnName == "EXPERIENCE_TYPE") {
			row->getValue(i, experienceType);
		} else if (columnName == "EXPERIENCE_AMOUNT") {
			row->getValue(i, experienceAmount);
		} else if (columnName == "FACTION_NAME") {
			row->getValue(i, factionName);
		} else if (columnName == "FACTION_AMOUNT") {
			row->getValue(i, factionAmount);
		} else if (columnName == "BANK_CREDITS") {
			row->getValue(i, bankCredits);
		} else if (columnName == "ITEM") {
			row->getValue(i, item);
		} else if (columnName == "PLANET_NAME") {
			row->getValue(i, planetName);
		} else if (columnName == "LOCATION_X") {
			String temp;
			row->getValue(i, temp);
			locationX = Integer::valueOf(temp);
		} else if (columnName == "LOCATION_Y") {
			String temp;
			row->getValue(i, temp);
			locationY = Integer::valueOf(temp);
		} else if (columnName == "LOCATION_Z") {
			String temp;
			row->getValue(i, temp);
			locationZ = Integer::valueOf(temp);
		} else if (columnName == "RADIUS") {
			String temp;
			row->getValue(i, temp);
			radius = Integer::valueOf(temp);
		} else if (columnName == "SIGNAL_NAME") {
			row->getValue(i, signalName);
		} else if (columnName == "MIN_TIME") {
			row->getValue(i, minTime);
		} else if (columnName == "MAX_TIME") {
			row->getValue(i, maxTime);
		} else if (columnName == "CREATURE_TYPE") {
			row->getValue(i, creatureType);
		} else if (columnName == "TARGET_SERVER_TEMPLATE") {
			row->getValue(i, targetServerTemplate);
		} else if (columnName == "SOCIAL_GROUP") {
			row->getValue(i, socialGroup);
		} else if (columnName == "COUNT") {
			row->getValue(i, count);
		} else if (columnName == "REQUIRED_REGION") {
			row->getValue(i, requiredRegion);
		} else if (columnName == "MIN_DISTANCE") {
			row->getValue(i, minDistance);
		} else if (columnName == "MAX_DISTANCE") {
			row->getValue(i, maxDistance);
		} else if (columnName == "DIRECTION") {
			row->getValue(i, direction);
		} else if (columnName == "REWARD_CREDITS") {
			row->getValue(i, rewardCredits);
		} else if (columnName == "LOOT_ITEM_NAME") {
			row->getValue(i, lootItemName);
		} else if (columnName == "LOOT_ITEMS_REQUIRED") {
			row->getValue(i, lootItemsRequired);
		} else if (columnName == "LOOT_DROP_PERCENT") {
			row->getValue(i, lootDropPercent);
		}
	}
}

const Vector<int> QuestTask::getPrerequisiteTasks() const {
	return prerequisiteTasks;
}

const Vector<int> QuestTask::getExclusionTasks() const {
	return exclusionTasks;
}

const String QuestTask::getAttachScript() const {
	return attachScript;
}

const String QuestTask::getJournalEntryTitle() const {
	return journalEntryTitle;
}

const String QuestTask::getJournalEntryDescription() const {
	return journalEntryDescription;
}

const Vector<int> QuestTask::getTasksOnComplete() const {
	return tasksOnComplete;
}

const Vector<int> QuestTask::getTasksOnFail() const {
	return tasksOnFail;
}

const String QuestTask::getTaskName() const {
	return taskName;
}

bool QuestTask::getIsVisible() const {
	return isVisible;
}

bool QuestTask::getShowSystemMessages() const {
	return showSystemMessages;
}

bool QuestTask::getAllowRepeats() const {
	return allowRepeats;
}

const String QuestTask::getMusicOnActivate() const {
	return musicOnActivate;
}

const String QuestTask::getTarget() const {
	return target;
}

const String QuestTask::QuestTask::getParameter() const {
	return parameter;
}

const String QuestTask::getGrantQuestOnComplete() const {
	return grantQuestOnComplete;
}

const String QuestTask::getGrantQuestOnFail() const {
	return grantQuestOnFail;
}

const String QuestTask::getExperienceType() const {
	return experienceType;
}

int QuestTask::getExperienceAmount() const {
	return experienceAmount;
}

const String QuestTask::getFactionName() const {
	return factionName;
}

int QuestTask::getFactionAmount() const {
	return factionAmount;
}

int QuestTask::getBankCredits() const {
	return bankCredits;
}

const String QuestTask::getItem() const {
	return item;
}

const String QuestTask::getPlanetName() const {
	return planetName;
}

float QuestTask::getLocationX() const {
	return locationX;
}

float QuestTask::getLocationY() const {
	return locationY;
}

float QuestTask::getLocationZ() const {
	return locationZ;
}

float QuestTask::getRadius() const {
	return radius;
}

const String QuestTask::getSignalName() const {
	return signalName;
}

int QuestTask::getMinTime() const {
	return minTime;
}

int QuestTask::getMaxTime() const {
	return maxTime;
}

const String QuestTask::getCreatureType() const {
	return creatureType;
}

const String QuestTask::getTargetServerTemplate() const {
	return targetServerTemplate;
}

const String QuestTask::getSocialGroup() const {
	return socialGroup;
}

const String QuestTask::getRequiredRegion() const {
	return requiredRegion;
}

int QuestTask::getCount() const {
	return count;
}

int QuestTask::getMinDistance() const {
	return minDistance;
}

int QuestTask::getMaxDistance() const {
	return maxDistance;
}

const String QuestTask::getDirection() const {
	return direction;
}

int QuestTask::getRewardCredits() const {
	return rewardCredits;
}

const String QuestTask::getLootItemName() const {
	return lootItemName;
}

int QuestTask::getLootItemsRequired() const {
	return lootItemsRequired;
}

int QuestTask::getLootDropPercent() const {
	return lootDropPercent;
}

QuestTasks::QuestTasks() {
}
void QuestTasks::parseDataTable(const DataTableIff& dTable) {
	for (int i = 0; i < dTable.getTotalRows(); ++i) {
		const DataTableRow* row = dTable.getRow(i);

		QuestTask* task = new QuestTask();
		task->parseDataTableRow(row, dTable);
		tasks.add(task);
	}
}

int QuestTasks::getNumberOfTasks() {
	return tasks.size();
}

QuestTask* QuestTasks::getTask(int taskNumber) {
	return tasks.get(taskNumber);
}