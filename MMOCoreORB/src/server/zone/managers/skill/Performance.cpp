#include "Performance.h"

bool Performance::isDance() {
	return type == PerformanceType::DANCE;
}

bool Performance::isMusic() {
	return type == PerformanceType::MUSIC;
}

String& Performance::getName() {
	return performanceName;
}

String& Performance::getRequiredSong() {
	return requiredSong;
}

String& Performance::getRequiredInstrument() {
	return requiredInstrument;
}

String& Performance::getRequiredDance() {
	return requiredDance;
}

String& Performance::getRequiredSkillMod() {
	return requiredSkillMod;
}

String& Performance::getMainloop() {
	return mainloop;
}

String& Performance::getFlourish1() {
	return requiredDance;
}

String& Performance::getFlourish2() {
	return requiredDance;
}

String& Performance::getFlourish3() {
	return flourish3;
}

String& Performance::getFlourish4() {
	return flourish4;
}

String& Performance::getFlourish5() {
	return flourish5;
}

String& Performance::getFlourish6() {
	return flourish6;
}

String& Performance::getFlourish7() {
	return flourish7;
}

String& Performance::getFlourish8() {
	return flourish8;
}

String& Performance::getIntro() {
	return intro;
}

String& Performance::getOutro() {
	return outro;
}

int Performance::getInstrumentAudioId() {
	return instrumentAudioId;
}

int Performance::getDanceVisualId() {
	return danceVisualId;
}

int Performance::getActionPointsPerLoop() {
	return actionPointsPerLoop;
}

int Performance::getType() {
	return type;
}

int Performance::getBaseXp() {
	return baseXp;
}

int Performance::getFlourishXpMod() {
	return flourishXpMod;
}

int Performance::getHealMindWound() {
	return healMindWound;
}

int Performance::getHealShockWound() {
	return healShockWound;
}

int Performance::getRequiredSkillModValue() {
	return requiredSkillModValue;
}

float Performance::getLoopDuration() {
	return loopDuration;
}

int Performance::getPerformanceIndex() {
	return performanceIndex;
}

void Performance::parseDataTableRow(int idx, DataTableRow* row) {
	performanceIndex = idx;
	row->getValue(0, performanceName);
	row->getValue(1, instrumentAudioId);
	row->getValue(2, requiredSong);
	row->getValue(3, requiredInstrument);
	row->getValue(4, requiredDance);
	row->getValue(5, danceVisualId);
	row->getValue(6, actionPointsPerLoop);
	row->getValue(7, loopDuration);

	uint32 typeHex;
	row->getValue(8, typeHex);

	if ((int)typeHex == PerformanceType::MUSIC) {
		type = PerformanceType::MUSIC;
	} else if ((int)typeHex == PerformanceType::DANCE) {
		type = PerformanceType::DANCE;
	}

	row->getValue(9, baseXp);
	row->getValue(10, flourishXpMod);
	row->getValue(11, healMindWound);
	row->getValue(12, healShockWound);
	row->getValue(13, requiredSkillMod);
	row->getValue(14, requiredSkillModValue);
	row->getValue(15, mainloop);
	row->getValue(16, flourish1);
	row->getValue(17, flourish2);
	row->getValue(18, flourish3);
	row->getValue(19, flourish4);
	row->getValue(20, flourish5);
	row->getValue(21, flourish6);
	row->getValue(22, flourish7);
	row->getValue(23, flourish8);
	row->getValue(24, intro);
	row->getValue(25, outro);
}