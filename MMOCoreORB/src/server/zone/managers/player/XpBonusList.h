#pragma once

namespace server {
namespace zone {
namespace managers {
namespace player {

class XpBonusList : public VectorMap<String, VectorMap<String, int> > {

};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;
