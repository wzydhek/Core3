#include "OnShipHit.h"

OnShipHit::OnShipHit(ShipObject* ship, const Vector3& hitDirection, int shipHitType, float newPercent, float oldPercent) : ObjectControllerMessage(ship->getObjectID(), 0x1B, 0x432) {
	float radius = ship->getBoundingRadius();

	writeFloat(Math::clamp(-radius, hitDirection.getX(), radius));
	writeFloat(Math::clamp(-radius, hitDirection.getY(), radius));
	writeFloat(Math::clamp(-radius, hitDirection.getZ(), radius));
	writeInt(shipHitType);
	writeFloat(newPercent);
	writeFloat(oldPercent);
}