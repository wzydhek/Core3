/*
 * SyncrhonizedUiListenHarvesterTask.h
 *
 *  Created on: 14/06/2010
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/installation/InstallationObject.h"

namespace server {
 namespace zone {
  namespace objects {
   namespace installation {


class SyncrhonizedUiListenInstallationTask : public Task, public Logger {
	ManagedWeakReference<InstallationObject*> installation;
public:
	SyncrhonizedUiListenInstallationTask(InstallationObject* inso);

	void run();
};


   }
  }

 }
}

using namespace server::zone::objects::installation;
