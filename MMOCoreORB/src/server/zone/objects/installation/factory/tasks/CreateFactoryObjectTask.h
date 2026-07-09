/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/objects/installation/factory/FactoryObject.h"

class CreateFactoryObjectTask : public Task {

	ManagedReference<FactoryObject* > factoryObject;

public:
	CreateFactoryObjectTask(FactoryObject* factory);

	void run();
};
