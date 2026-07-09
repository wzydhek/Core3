#pragma once

#include "engine/engine.h"
#include "engine/service/proto/BaseMessage.h"

class PackedQuaternion : public Object {
private:
	static constexpr float directionScale = 127.f;
	static constexpr float directionScaleInv = 1.f / directionScale;

protected:
	int8 w;
	int8 x;
	int8 y;
	int8 z;

public:
	PackedQuaternion();

	PackedQuaternion(const Quaternion& value);

	void set(const Quaternion& value);

	void parse(Message* message);

	void write(Message* message) const;

	Quaternion get() const;
};
