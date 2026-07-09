/*
 * StringIdParam.h
 *
 *  Created on: 22-feb-2009
 *      Author: TheAnswer
 */

#pragma once

#include "templates/params/TemplateBase.h"
#include "templates/params/primitives/StringParam.h"

class StringIdParamData {
	StringParam file;
	StringParam stringId;
public:
	StringIdParamData(const String& File, const String& id);

	StringIdParamData(const StringParam& File, const StringParam& id);

	StringIdParamData(const StringParam& fullString);

	StringIdParamData();


	bool operator<(const StringIdParamData& val) const;

	bool operator>(const StringIdParamData& val) const;

	StringIdParamData& operator+=(const StringIdParamData& val);

	StringIdParamData& operator-=(const StringIdParamData& val);


	friend class StringIdParam;
};

class StringIdParam : public TemplateBase<StringIdParamData> {

public:
	StringIdParam(const String& str);

	StringIdParam();

	~StringIdParam();

	String toString() const;

	virtual bool parse(Chunk* source);

	StringIdParam& operator=(const String& str);

	StringIdParam& operator=(const StringIdParamData& custom);

	String getFullString() const;

};
