//
// Created by Greg Slomin on 5/2/18.
//

#pragma once

#include "engine/engine.h"
#include "system/lang/Time.h"

namespace server {
namespace zone {
namespace managers {
namespace frs {

class FrsTimeMap : public VectorMap<uint64, Time> {
public:
	FrsTimeMap();
};

} // namespace frs
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::frs;
