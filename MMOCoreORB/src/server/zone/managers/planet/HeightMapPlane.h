#pragma once

#include "system/lang.h"

namespace server {
namespace zone {
namespace managers {
namespace planet {

class HeightMapPlane {
	byte* buffer;

	int index;

	int planeSize;

public:
	HeightMapPlane(int idx, int size = 256);

	~HeightMapPlane();

	// getters
	byte* getBuffer();

	float getHeight(int x, int y);

	int getIndex();

	// setters
	void setIndex(int idx);
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;
