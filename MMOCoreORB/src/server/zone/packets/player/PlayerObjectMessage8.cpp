#include "PlayerObjectMessage8.h"

PlayerObjectMessage8::PlayerObjectMessage8(PlayerObjectImplementation* play) : BaseLineMessage(play->getObjectID(), 0x504C4159, 8, 0x07) {
	// experiences
	const DeltaVectorMap<String, int>* xpList = play->getExperienceList();
	xpList->insertToMessage(this);

	// waypoints
	play->insertWaypointListToMessage(this);

	// force bar stats
	insertInt(play->getForcePower());
	insertInt(play->getForcePowerMax());

	// completed quests
	const DeltaBitArray* completedQuests = play->getCompletedQuests();
	completedQuests->insertToMessage(this);

	// active quests
	const DeltaBitArray* activeQuests = play->getActiveQuests();
	activeQuests->insertToMessage(this);

	// quests
	const DeltaVectorMap<uint32, PlayerQuestData>* quests = play->getPlayerQuestsData();
	quests->insertToMessage(this);

	//
	insertInt(0);
	insertInt(0);

	setSize();
}