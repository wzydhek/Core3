#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace player {

class JukeboxSong : public Object {

protected:
	String stringId, songFile;

public:
	JukeboxSong();

	~JukeboxSong();

	JukeboxSong(const JukeboxSong& obj);

	JukeboxSong(String sid, String sfile);

	String getSongFile();

	String getStringId();
};

} // namespace player
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::player;
