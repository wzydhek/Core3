#pragma once

#include "templates/datatables/DataTableRow.h"

class PerformEffect {
	int effectIndex;
	String effectName;
	int effectId;
	int effectLevel;
	bool isDance;
	bool isMusic;
	int requiredSkillModValue;
	bool requiredPerform;
	int targetType;
	float effectDuration;
	int effectActionCost;
	String effectFile;
	String effectMessage;

public:
	enum {
		TARGET_STATIONARY = 1,
		TARGET_OTHER = 2,
		TARGET_SELF = 3
	};
	enum {
		DAZZLE = 1,
		DISTRACT = 2,
		SPOTLIGHT = 3,
		COLORLIGHTS = 4,
		SMOKEBOMB = 5,
		FIREJETS = 6,
		VENTRILOQUISM = 7
	};

	bool isDanceEffect();

	bool isMusicEffect();

	String& getName();

	String& getEffectFile();

	String& getEffectMessage();

	int getEffectLevel();

	int getEffectId();

	int getRequiredSkillModValue();

	bool isPerformRequired();

	int getTargetType();

	float getEffectDuration();

	int getEffectActionCost();


	void parseDataTableRow(int idx, DataTableRow* row);
};
