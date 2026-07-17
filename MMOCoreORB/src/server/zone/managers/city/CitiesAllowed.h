/*
 * CitiesAllowed.h
 *
 *  Created on: Feb 23, 2012
 *      Author: xyborn
 */

#pragma once

namespace server {
namespace zone {
namespace managers {
namespace city {

class CitiesAllowed : public HashTable<String, Vector<byte> > {
};

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;
