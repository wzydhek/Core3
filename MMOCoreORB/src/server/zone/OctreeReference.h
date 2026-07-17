#pragma once

#include "engine/engine.h"
#include "server/zone/Octree.h"

namespace server {
namespace zone {

#ifdef WITH_STM
	class OctreeReference : public TransactionalReference<Octree*> {
#else
	class OctreeReference : public Reference<server::zone::Octree*> {
#endif
	public:
		bool toBinaryStream(ObjectOutputStream* stream);
		bool parseFromBinaryStream(ObjectInputStream* stream);

		server::zone::Octree* operator=(server::zone::Octree* obj);
	};

} // namespace zone
} // namespace server

using namespace server::zone;
