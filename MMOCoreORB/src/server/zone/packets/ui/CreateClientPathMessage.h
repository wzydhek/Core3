/*
 * CreateClientPathMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "engine/engine.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class CreateClientPathMessage : public BaseMessage {
	int coordinateCount;
public:
	CreateClientPathMessage();

	void addCoordinate(float x, float z, float y);

	void addCoordinate(const Vector3& position);

	void updateCount();

	void drawBoundingSphere(const Vector3& position, const Matrix4& rotation, const Sphere& sphere, float divisions = 6);

	void drawBoundingBox(const Vector3& position, const Matrix4& rotation, const AABB& box);
};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
