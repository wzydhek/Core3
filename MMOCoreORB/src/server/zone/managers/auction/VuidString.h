/*
 * VuidString.h
 *
 *  Created on: Jun 11, 2012
 *      Author: kyle
 */

#pragma once

#include "engine/engine.h"
#include "system/lang/String.h"

class VuidString : public String {
public:

	VuidString();

	~VuidString();

	VuidString(const String& val);

	VuidString(const char* str);

	VuidString(const VuidString& val);

	int compareTo(const VuidString& str) const;
};
