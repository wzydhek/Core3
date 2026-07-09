/*
		Copyright <SWGEmu>
	See file COPYING for copying conditions.*/

/*
* CommandQueue.h
*
* Created on: Jan. 1, 2022
* Author: Hakry
*/

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/creature/variables/CommandQueueActionVector.h"

// #define DEBUG_QUEUE

class CommandQueueTask;

class CommandQueue : public Object, public Logger {
	mutable Mutex queueMutex;

	enum State {
		NONE, WAITING, RUNNING, DELAY
	};

	WeakReference<CreatureObject*> weakCreature;
	CommandQueueActionVector queueVector;
	Reference<CommandQueueTask*> queueTask;
	State state = NONE;
	static const int DEFAULTTIME = 50;
#ifdef DEBUG_QUEUE
	uint64 runNumber = 0;
	Time lastRun;
#endif // DEBUG_QUEUE

private:
	void removeAction(CommandQueueAction* actionToDelete);
	CommandReference<CommandQueueAction*> getNextAction();

public:
	CommandQueue(CreatureObject* creature);

	~CommandQueue();

	void run();
	int handleRunningState();

	int checkActions(CreatureObject* creature);
	void enqueueCommand(unsigned int actionCRC, unsigned int actionCount, uint64 targetID, const UnicodeString& arguments, int priority, int compareCounter);
	void sendCommand(uint32 crc, const UnicodeString& args, uint64 targetID, int priority);
	void clearQueueAction(unsigned int actioncntr, float timer, unsigned int tab1, unsigned int tab2);
	void clearQueueActions(bool combatOnly);

	int getQueueSize() const;

	void deleteQueueAction(uint32 actionCount);

	String toString() const;

	String toStringData() const;
};

class CommandQueueTask : public Task, public Logger {
private:
	WeakReference<CommandQueue*> weakQueue;

public:
	CommandQueueTask(CommandQueue* queue);

	void run();
};
