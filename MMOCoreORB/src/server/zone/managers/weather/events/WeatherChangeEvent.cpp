#include "WeatherChangeEvent.h"

WeatherChangeEvent::WeatherChangeEvent(WeatherManager* weatherManager) : Task() {
	this->weatherManager = weatherManager;
}

void WeatherChangeEvent::run() {
	ManagedReference<WeatherManager*> wm = weatherManager.get();

	if (wm != nullptr) {
		wm->createNewWeatherPattern();
	}
}