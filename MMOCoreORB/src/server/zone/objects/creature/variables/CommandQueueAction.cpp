/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "CommandQueueAction.h"

#include "server/zone/objects/creature/CreatureObject.h"

CommandQueueAction::CommandQueueAction(CreatureObject* cr, uint64 tar, uint32 command, uint32 acntr, const UnicodeString& amod) {
	actionCounter = acntr;

	target = tar;

	arguments = amod;

	creature = cr;
	queueCommand = command;
	compareToCounter = actionCounter;
}

void CommandQueueAction::clear(float timer, uint32 tab1, uint32 tab2) {
	creature->clearQueueAction(actionCounter, timer, tab1, tab2);
}

void CommandQueueAction::run() {

}

void CommandQueueAction::clearError(uint32 tab1, uint32 tab2) {
	clear(0.0f, tab1, tab2);
}

int CommandQueueAction::compareTo(CommandQueueAction* action) {
	if (compareToCounter == action->compareToCounter) {
		if (this == action)
			return 0;
		else if (this < action)
			return 1;
		else
			return -1;
	} else if (compareToCounter < action->compareToCounter)
		return 1;
	else
		return -1;
}

void CommandQueueAction::setCompareToCounter(int c) {
	compareToCounter = c;
}

int CommandQueueAction::getCompareToCounter() {
	return compareToCounter;
}

CreatureObject* CommandQueueAction::getCreature() {
	return creature;
}

uint32 CommandQueueAction::getCommand() {
	return queueCommand;
}

uint64 CommandQueueAction::getTarget() {
	return target;
}

uint32 CommandQueueAction::getActionCounter() {
	return actionCounter;
}

UnicodeString CommandQueueAction::getArguments() {
	return arguments;
}