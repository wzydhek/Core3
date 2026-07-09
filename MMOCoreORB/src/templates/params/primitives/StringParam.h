/*
 * StringParam.h
 *
 *  Created on: 22-feb-2009
 *      Author: TheAnswer
 */

#pragma once

#include "templates/params/TemplateBase.h"

class StringParam : public TemplateBase<String> {
public:
	StringParam();

	StringParam(const String& val);

	StringParam(const StringParam& p);

	virtual String toString() const;

	virtual bool parse(engine::util::Chunk* source);

	StringParam& operator=(const String& val);

	StringParam& operator=(const StringParam& val);

	String& operator-=(const String& val);
};
