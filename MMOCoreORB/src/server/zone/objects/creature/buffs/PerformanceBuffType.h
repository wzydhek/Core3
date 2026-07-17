#pragma once

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class PerformanceBuffType {
	public:
		enum {
			DANCE_MIND      = 1,
			MUSIC_FOCUS     = 2,
			MUSIC_WILLPOWER = 3
		};
};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;
