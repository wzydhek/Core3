#include "CampAbandonTask.h"

CampAbandonTask::CampAbandonTask(CampSiteActiveArea* camp) {
	campSite = camp;
}

void CampAbandonTask::run() {
	if (campSite == nullptr)
		return;

	Locker locker(campSite);
	campSite->abandonCamp();
}