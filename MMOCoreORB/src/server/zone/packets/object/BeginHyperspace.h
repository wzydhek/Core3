//
// Created by g on 12/20/17.
//

#pragma once

#include "ObjectControllerMessage.h"

class BeginHyperspaceMessage : public ObjectControllerMessage {
public:
	BeginHyperspaceMessage(uint64 objid, const String& location, float x, float y, float z);
};
