#include "JukeboxSelectionSuiCallback.h"

JukeboxSelectionSuiCallback::JukeboxSelectionSuiCallback(ZoneServer* server) : SuiCallback(server) {
}

void JukeboxSelectionSuiCallback::run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!suiBox->isListBox() || cancelPressed)
		return;

	SuiListBox* listBox = cast<SuiListBox*>(suiBox);

	ManagedReference<SceneObject*> terminal = listBox->getUsingObject().get();

	if (terminal == nullptr)
		return;

	ManagedReference<Jukebox*> jukebox = cast<Jukebox*>(terminal.get());

	if (jukebox == nullptr)
		return;

	PlayerManager* playerManager = player->getZoneServer()->getPlayerManager();

	if (playerManager == nullptr)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	if (index == -1)
		return;

	JukeboxSong* song = playerManager->getJukeboxSong(index);

	String songFile = song->getSongFile();

	Locker clocker(jukebox, player);

	jukebox->stopPlaying();
	jukebox->startPlaying(songFile);
}