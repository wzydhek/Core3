#include "CreateFactoryObjectTask.h"

CreateFactoryObjectTask::CreateFactoryObjectTask(FactoryObject* factory) : Task() {
	factoryObject = factory;
}

void CreateFactoryObjectTask::run() {
	Locker _locker(factoryObject);

	factoryObject->createNewObject();
}