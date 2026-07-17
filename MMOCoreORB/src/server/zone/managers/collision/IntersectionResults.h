/*
 * IntersectionResults.h
 *
 *  Created on: Jul 3, 2013
 *      Author: TheAnswer
 */

#pragma once

namespace server {
namespace zone {
namespace managers {
namespace collision {

class IntersectionResults : public SortedVector<IntersectionResult> {

};

} // namespace collision
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::collision;
