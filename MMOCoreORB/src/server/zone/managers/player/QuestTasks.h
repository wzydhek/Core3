#pragma once

#include "system/lang/String.h"
#include <system/lang/Integer.h>
#include <system/util/Vector.h>
#include "templates/datatables/DataTableIff.h"
#include "templates/datatables/DataTableRow.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class UnknownDatatableException : public sys::lang::Exception {
public:
	UnknownDatatableException();

	UnknownDatatableException(const String& msg);
};

class QuestTask : public Object  {

protected:
	Vector<int> prerequisiteTasks;
	Vector<int> exclusionTasks;
	String attachScript;
	String journalEntryTitle;
	String journalEntryDescription;
	Vector<int> tasksOnComplete;
	Vector<int> tasksOnFail;
	String taskName;
	bool isVisible;
	bool showSystemMessages;
	bool allowRepeats;
	String musicOnActivate;
	String target;
	String parameter;
	String grantQuestOnComplete;
	String grantQuestOnFail;
	String experienceType;
	int experienceAmount;
	String factionName;
	int factionAmount;
	int bankCredits;
	String item;
	String planetName;
	float locationX;
	float locationY;
	float locationZ;
	float radius;
	String signalName;
	int minTime;
	int maxTime;
	String creatureType;
	String targetServerTemplate;
	String socialGroup;
	String requiredRegion;
	int count;
	int minDistance;
	int maxDistance;
	String direction;
	int rewardCredits;
	String lootItemName;
	int lootItemsRequired;
	int lootDropPercent;


public:
	QuestTask();

	void parseDataTableRow(const DataTableRow* row, const DataTableIff& dTable);

	const Vector<int> getPrerequisiteTasks() const;

	const Vector<int> getExclusionTasks() const;

	const String getAttachScript() const;

	const String getJournalEntryTitle() const;

	const String getJournalEntryDescription() const;

	const Vector<int> getTasksOnComplete() const;

	const Vector<int> getTasksOnFail() const;

	const String getTaskName() const;

	bool getIsVisible() const;

	bool getShowSystemMessages() const;

	bool getAllowRepeats() const;

	const String getMusicOnActivate() const;

	const String getTarget() const;

	const String getParameter() const;

	const String getGrantQuestOnComplete() const;

	const String getGrantQuestOnFail() const;

	const String getExperienceType() const;

	int getExperienceAmount() const;

	const String getFactionName() const;

	int getFactionAmount() const;

	int getBankCredits() const;

	const String getItem() const;

	const String getPlanetName() const;

	float getLocationX() const;

	float getLocationY() const;

	float getLocationZ() const;

	float getRadius() const;

	const String getSignalName() const;

	int getMinTime() const;

	int getMaxTime() const;

	const String getCreatureType() const;

	const String getTargetServerTemplate() const;

	const String getSocialGroup() const;

	const String getRequiredRegion() const;

	int getCount() const;

	int getMinDistance() const;

	int getMaxDistance() const;

	const String getDirection() const;

	int getRewardCredits() const;

	const String getLootItemName() const;

	int getLootItemsRequired() const;

	int getLootDropPercent() const;
};

class QuestTasks : public Object {

protected:
	Vector<QuestTask*> tasks;
public:
	QuestTasks();

	void parseDataTable(const DataTableIff& dTable);

	int getNumberOfTasks();

	QuestTask* getTask(int taskNumber);
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;
