//
// Created by g on 12/20/17.
//

#pragma once

#include "ObjectControllerMessage.h"

class OrientForHyperspaceMessage : public ObjectControllerMessage {
public:
	OrientForHyperspaceMessage(uint64 objid, const String& zone, float x, float y, float z);
};
