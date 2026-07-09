#include "ThreatMapClearObserversTask.h"

ThreatMapClearObserversTask::ThreatMapClearObserversTask(const ThreatMap& map, ThreatMapObserver* obs) : threatMap(map), threatMapObserver(obs) {
}

void ThreatMapClearObserversTask::run() {
	while (threatMap.size() > 0) {
		TangibleObject* tano = threatMap.elementAt(0).getKey();

		if (tano != nullptr && threatMapObserver != nullptr) {
			Locker clocker(tano);

			tano->dropObserver(ObserverEventType::HEALINGRECEIVED, threatMapObserver);
		}

		threatMap.remove(0);
	}
}