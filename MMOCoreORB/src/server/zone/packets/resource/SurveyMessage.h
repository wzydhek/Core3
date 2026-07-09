/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class SurveyMessage : public BaseMessage {
public:
	int listSize;
	
	SurveyMessage();
	
	void add(float loc_x, float loc_y, float percentage);
	
	void updateSize();

};
