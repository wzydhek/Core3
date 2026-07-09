#include "JukeboxSong.h"

JukeboxSong::JukeboxSong() {
}

JukeboxSong::~JukeboxSong() {
}

JukeboxSong::JukeboxSong(const JukeboxSong& obj) : Object() {
	stringId = obj.stringId;
	songFile = obj.songFile;
}

JukeboxSong::JukeboxSong(String sid, String sfile) : Object() {
	stringId = sid;
	songFile = sfile;
}

String JukeboxSong::getSongFile() {
	return songFile;
}

String JukeboxSong::getStringId() {
	return stringId;
}