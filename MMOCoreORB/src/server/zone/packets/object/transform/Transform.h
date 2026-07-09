#ifndef TRANSFORM_H_
#define TRANSFORM_H_

// #define TRANSFORM_DEBUG

#include "server/zone/objects/scene/SceneObject.h"


class Transform {
protected:
	uint32 timeStamp;
	uint32 moveCount;
	uint64 parentID;

	Quaternion direction;
	Vector3 position;

	float speed;

public:
	const static constexpr float POSITION_MOD = 6.f; // broadcast position update distance multiplier

	const static int MIN_DELTA = 200; // minimum ms elapsed between updates
	const static int MID_DELTA = 400; // ideal ms between low priority update
	const static int MAX_DELTA = 800; // maximum ms before high priority update

	const static int SYNC_DELTA = 10000; // minimum ms before synchronize update
	const static int SYNC_COUNT = 50; // minimum moveCount for synchronize update

	const static int INVALID_POSITION = 1;
	const static int TIME_VALIDATED = 2;
	const static int FULL_VALIDATED = 3;

	constexpr static float UPDATE_THRESHOLD = 0.015625f;

	Transform();

	void parseDataTransform(Message* message);

	void parseDataTransformWithParent(Message* message);

	void parseDirection(Message* message);

	void parsePosition(Message* message);

	uint32 getTimeStamp() const;

	uint32 getMoveCount() const;

	uint64 getParentID() const;

	float getPositionX() const;

	float getPositionY() const;

	float getPositionZ() const;

	float getSpeed() const;

	const Vector3& getPosition() const;

	const Quaternion& getDirection() const;

	bool isPositionValid() const;

	bool isPostureValid(int posture) const;

	bool isInertiaUpdate(const Vector3& creoPosition, const Quaternion* creoDirection, float creoSpeed) const;

	bool isSynchronizeUpdate(const Quaternion* creoDirection, float creoSpeed) const;

	bool isYawUpdate(const Quaternion* creoDirection) const;

	float get2dSquaredDistance(const Vector3& creoPosition) const;

	float get3dSquaredDistance(const Vector3& creoPosition) const;

	float getSquaredMoveScale(const Vector3& creoPosition, float interval) const;

	float getMoveScale(const Vector3& creoPosition, float interval) const;

	float getTurnScale(const Quaternion* creoDirection, float radians) const;

	Vector3 predictPosition(const Vector3& creoPosition, const Quaternion* creoDirection, int deltaTime) const;

	bool isValidParentType(SceneObject* parent);

#ifdef TRANSFORM_DEBUG
	void sendDebug(CreatureObject* creature, const String& message, const Vector3& newPosition, int deltaTime) const;

	void sendFlyText(CreatureObject* creature, const String& type, int deltaTime) const;

	void sendPathMessage(CreatureObject* creature, const Vector3& newPosition) const;

	void sendSystemMessage(CreatureObject* creature, const Vector3& newPosition, const String& type, int deltaTime) const;
#endif // TRANSFORM_DEBUG
};

#endif // TRANSFORM_H_
