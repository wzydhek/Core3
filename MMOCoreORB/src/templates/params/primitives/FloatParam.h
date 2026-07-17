/*
 * FloatParam.h
 *
 *  Created on: 22-feb-2009
 *      Author: TheAnswer
 */

#pragma once

#include "templates/params/TemplateBase.h"

namespace templates {
namespace params {
namespace primitives {

class FloatParam : public TemplateBase<float> {
	float min;
	float max;
public:
	FloatParam();

	FloatParam(float m);

	FloatParam& operator=(float val);

	void setMin(float m);

	void setMax(float m);

	String toString() const;

	static bool toBinaryStream(ObjectOutputStream* stream);

	/*static bool parseFromString(T* address, const sys::lang::String& value, int version = 0) {
		return address->parseFromString(value, version);
	}*/

	static bool parseFromBinaryStream(ObjectInputStream* stream);


	virtual bool parse(engine::util::Chunk* source);

	float getMin() const;

	float getMax() const;
};

} // namespace primitives
} // namespace params
} // namespace templates

using namespace templates::params::primitives;
