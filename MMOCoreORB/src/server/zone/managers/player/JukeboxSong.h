#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

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
