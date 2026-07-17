/*
 * QuadTreeReference.h
 *
 *  Created on: 03/09/2011
 *      Author: TheAnswer
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/QuadTree.h"

namespace server {
namespace zone {

#ifdef WITH_STM
	class QuadTreeReference : public TransactionalReference<QuadTree*> {
#else
	class QuadTreeReference : public Reference<server::zone::QuadTree*> {
#endif
	public:
		bool toBinaryStream(ObjectOutputStream* stream);
		bool parseFromBinaryStream(ObjectInputStream* stream);

		server::zone::QuadTree* operator=(server::zone::QuadTree* obj);
	};

} // namespace zone
} // namespace server

using namespace server::zone;
