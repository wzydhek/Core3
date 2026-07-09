#include "PerformEffect.h"

bool PerformEffect::isDanceEffect() {
	return isDance;
}

bool PerformEffect::isMusicEffect() {
	return isMusic;
}

String& PerformEffect::getName() {
	return effectName;
}

String& PerformEffect::getEffectFile() {
	return effectFile;
}

String& PerformEffect::getEffectMessage() {
	return effectMessage;
}

int PerformEffect::getEffectLevel() {
	return effectLevel;
}

int PerformEffect::getEffectId() {
	return effectId;
}

int PerformEffect::getRequiredSkillModValue() {
	return requiredSkillModValue;
}

bool PerformEffect::isPerformRequired() {
	return requiredPerform;
}

int PerformEffect::getTargetType() {
	return targetType;
}

float PerformEffect::getEffectDuration() {
	return effectDuration;
}

int PerformEffect::getEffectActionCost() {
	return effectActionCost;
}

void PerformEffect::parseDataTableRow(int idx, DataTableRow* row) {
	effectIndex = idx;
	String tempString, tempString2;

	row->getValue(0, tempString);
	tempString2 = tempString.subString(tempString.length() - 1);
	effectLevel = Integer::valueOf(tempString2);
	tempString = tempString.replaceAll(tempString2, "");
	effectName = tempString.toLowerCase();

	if (effectName == "dazzle")
		effectId = DAZZLE;
	else if (effectName == "distract")
		effectId = DISTRACT;
	else if (effectName == "spotlight")
		effectId = SPOTLIGHT;
	else if (effectName == "colorlights")
		effectId = COLORLIGHTS;
	else if (effectName == "smokebomb")
		effectId = SMOKEBOMB;
	else if (effectName == "firejets")
		effectId = FIREJETS;
	else if (effectName == "ventriloquism")
		effectId = VENTRILOQUISM;

	row->getValue(1, tempString);

	if (tempString.contains("dance"))
		isDance = true;
	if (tempString.contains("music"))
		isMusic = true;

	row->getValue(2, requiredSkillModValue);
	row->getValue(3, requiredPerform);
	row->getValue(4, targetType);

	row->getValue(5, effectDuration);
	row->getValue(6, effectActionCost);

	if (effectId == DAZZLE) {
		effectFile = "clienteffect/entertainer_dazzle_level_" + String::valueOf(effectLevel) + ".cef";
		effectMessage = "effect_perform_dazzle";
	} else if (effectId == DISTRACT) {
		effectFile = "clienteffect/entertainer_distract_level_" + String::valueOf(effectLevel) + ".cef";
		effectMessage = "effect_perform_distract";
	} else if (effectId == SPOTLIGHT) {
		effectFile = "clienteffect/entertainer_spot_light_level_" + String::valueOf(effectLevel) + ".cef";
		effectMessage = "effect_perform_spot_light";
	} else if (effectId == COLORLIGHTS) {
		effectFile = "clienteffect/entertainer_color_lights_level_" + String::valueOf(effectLevel) + ".cef";
		effectMessage = "effect_perform_color_lights";
	} else if (effectId == SMOKEBOMB) {
		effectFile = "clienteffect/entertainer_smoke_bomb_level_" + String::valueOf(effectLevel) + ".cef";
		effectMessage = "effect_perform_smoke_bomb";
	} else if (effectId == FIREJETS) {
		effectFile = "clienteffect/entertainer_fire_jets_level_" + String::valueOf(effectLevel) + ".cef";
		effectMessage = "effect_perform_fire_jets";
	} else if (effectId == VENTRILOQUISM) {
		effectFile = "clienteffect/entertainer_ventriloquism_level_" + String::valueOf(effectLevel) + ".cef";
		effectMessage = "effect_perform_ventriloquism";
	}
}