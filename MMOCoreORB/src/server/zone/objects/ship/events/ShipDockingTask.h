#pragma once

#include "engine/engine.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/packets/ship/ShipUpdateTransformMessage.h"
#include "server/zone/packets/scene/PlayClientEffectLocMessage.h"

class ShipDockingTask: public Task, public Logger {
private:
	const static int DURATION_MIN = 10000;
	const static int DURATION_MAX = 60000;

	const static int INTERVAL_INITIALIZE = 2000;
	const static int INTERVAL_TRANSFORM = 200;
	const static int INTERVAL_FINALIZE = 5000;

	constexpr static float SPEED_MIN = 10.f;
	constexpr static float SPEED_MAX = 25.f;

	enum DockingStage : int {
		INITIALIZE = 0,
		TRANSFORM = 1,
		FINALIZE = 2,
	};

protected:
	ManagedWeakReference<ShipObject*> shipRef;
	ManagedWeakReference<ShipObject*> targetRef;
	SpaceTransform dockTransform;

	uint64 timeStart;
	uint64 timeTotal;

	float rotationTime;
	float positionTime;

	int dockingStage;
	bool interlockStatus;

public:
	static bool isShipValid(ShipObject* ship);

	static bool isTargetValid(ShipObject* ship);

	static bool isDocking(ShipObject* ship);

	ShipDockingTask(ShipObject* ship, ShipObject* target);

	void run();

private:
	uint64 getTimeElapsed() const;

	void setSpeed(ShipObject* ship);

	void setTimeTotal(ShipObject* ship);

	void initializeDocking(ShipObject* ship, ShipObject* target);

	void updateTransform(ShipObject* ship, ShipObject* target);

	void finalizeDocking(ShipObject* ship, ShipObject* target);

	void notifyObservers(ShipObject* ship, ShipObject* target);

	void sendSystemMessage(ShipObject* ship, const String& string);

	void sendEffectMessage(ShipObject* ship, const String& effect);

	void clearDockingState(ShipObject* ship, ShipObject* target) const;

	void setDockingTransform(ShipObject* ship, ShipObject* target);

	void setAppearanceTransform(ShipObject* ship, ShipObject* target);

	bool checkLineOfSight(ShipObject* ship, ShipObject* target);

	Vector3 getBoundingPosition(ShipObject* ship, const Vector3& axis);

	Vector3 getBoundingAxis(ShipObject* ship, ShipObject* target);

	Vector3 getRotationAxis(const Vector3& axis);
};
