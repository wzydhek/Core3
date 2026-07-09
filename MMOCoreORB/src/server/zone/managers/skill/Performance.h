/*
 * Performance.h
 *
 *  Created on: 19/08/2010
 *      Author: victor
 */

#pragma once

#include "templates/datatables/DataTableRow.h"

class PerformanceType {
public:
	enum {
		DANCE  = -1788534963,
		MUSIC  = 866729052
	};

};

class Performance {
	int performanceIndex;
	String performanceName;
	int instrumentAudioId;
	String requiredSong;
	String requiredInstrument;
	String requiredDance;
	int danceVisualId;
	int actionPointsPerLoop;
	float loopDuration;
	int type;
	int baseXp;
	int flourishXpMod;
	int healMindWound;
	int healShockWound;
	String requiredSkillMod;
	int requiredSkillModValue;
	String mainloop;
	String flourish1;
	String flourish2;
	String flourish3;
	String flourish4;
	String flourish5;
	String flourish6;
	String flourish7;
	String flourish8;
	String intro;
	String outro;

public:

	bool isDance();

	bool isMusic();

	String& getName();

	String& getRequiredSong();

	String& getRequiredInstrument();

	String& getRequiredDance();

	String& getRequiredSkillMod();

	String& getMainloop();

	String& getFlourish1();

	String& getFlourish2();

	String& getFlourish3();

	String& getFlourish4();

	String& getFlourish5();

	String& getFlourish6();

	String& getFlourish7();

	String& getFlourish8();

	String& getIntro();

	String& getOutro();

	int getInstrumentAudioId();

	int getDanceVisualId();

	int getActionPointsPerLoop();

	int getType();

	int getBaseXp();

	int getFlourishXpMod();

	int getHealMindWound();

	int getHealShockWound();

	int getRequiredSkillModValue();

	float getLoopDuration();

	int getPerformanceIndex();

	void parseDataTableRow(int idx, DataTableRow* row);

};
