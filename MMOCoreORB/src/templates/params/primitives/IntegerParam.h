/*
 * IntegerParam.h
 *
 *  Created on: 22-feb-2009
 *      Author: TheAnswer
 */

#pragma once

#include "templates/params/TemplateBase.h"

class IntegerParam : public TemplateBase<int> {

public:
	IntegerParam();

	IntegerParam(const IntegerParam& p);

	IntegerParam& operator=(int val);

	IntegerParam& operator=(const IntegerParam& param);

	String toString() const;

	virtual bool parse(engine::util::Chunk* source);

};
