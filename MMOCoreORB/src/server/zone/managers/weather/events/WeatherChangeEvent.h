/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include"server/zone/managers/weather/WeatherManager.h"

namespace server {
namespace zone {
namespace managers {
namespace weather {
namespace events {

class WeatherChangeEvent : public Task {

	ManagedWeakReference<WeatherManager*> weatherManager;

public:
	WeatherChangeEvent(WeatherManager* weatherManager);

	void run();

};

}
}
}
}
}

using namespace server::zone::managers::weather::events;
