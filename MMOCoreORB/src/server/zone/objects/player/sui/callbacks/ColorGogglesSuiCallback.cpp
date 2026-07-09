#include "ColorGogglesSuiCallback.h"
#include "server/zone/objects/player/sui/colorbox/SuiColorBox.h"

ColorGogglesSuiCallback::ColorGogglesSuiCallback(ZoneServer* serv) : SuiCallback(serv) {
}

void ColorGogglesSuiCallback::run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
	bool cancelPressed = (eventIndex == 1);

	if (!sui->isColorPicker() || cancelPressed)
		return;

	if (!creature->isPlayerCreature())
		return;

	SuiColorBox* cBox = cast<SuiColorBox*>(sui);

	int index = Integer::valueOf(args->get(0).toString());

	String palette = cBox->getColorPalette();

	ManagedReference<SceneObject*> goggles = cBox->getUsingObject().get();

	if (goggles == nullptr)
		return;

	ManagedReference<TangibleObject*> gogglesTano = goggles->asTangibleObject();

	if (gogglesTano != nullptr) {
		Locker locker(gogglesTano, creature);

		gogglesTano->setCustomizationVariable(palette, index, true);
	}
}