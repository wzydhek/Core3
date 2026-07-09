#include "StringIdParam.h"

StringIdParamData::StringIdParamData(const String& File, const String& id) {
	file = File;
	stringId = id;
}

StringIdParamData::StringIdParamData(const StringParam& File, const StringParam& id) {
	file = File;
	stringId = id;
}

StringIdParamData::StringIdParamData(const StringParam& fullString) {
	String str = fullString.get();

	int idx = str.indexOf(":");

	if (idx != -1) {
		file = str.subString(1, idx);
		stringId = str.subString(idx + 1);
	}
}

StringIdParamData::StringIdParamData() {
	file = "";
	stringId = "";
}

bool StringIdParamData::operator<(const StringIdParamData& val) const {
	return false;
}

bool StringIdParamData::operator>(const StringIdParamData& val) const {
	return false;
}

StringIdParamData& StringIdParamData::operator+=(const StringIdParamData& val) {
	return *this;
}

StringIdParamData& StringIdParamData::operator-=(const StringIdParamData& val) {
	return *this;
}

StringIdParam::StringIdParam(const String& str) : TemplateBase<StringIdParamData>(StringIdParamData(str)) {
	setType(STRINGID);
}

StringIdParam::StringIdParam() : TemplateBase<StringIdParamData>(StringIdParamData("", "")) {
	setType(STRINGID);
}

StringIdParam::~StringIdParam() {
}

String StringIdParam::toString() const {
	return getFullString();
}

bool StringIdParam::parse(Chunk* source) {
	int readCase = source->readByte();

	if (readCase != 1) {
		// create(StringIdParamData());
		return false;
	}

	StringParam stfFile;
	stfFile.parse(source);

	StringParam stringId;
	stringId.parse(source);

	create(StringIdParamData(stfFile, stringId));

	return true;
}

StringIdParam& StringIdParam::operator=(const String& str) {
	create(StringIdParamData(str));

	return *this;
}

StringIdParam& StringIdParam::operator=(const StringIdParamData& custom) {
	create(custom);

	return *this;
}

String StringIdParam::getFullString() const {
	String file = get().file.get();
	// std::cout << "testFile:[" << file.toStdString() << "]\n";

	String stringId = get().stringId.get();
	// std::cout << "testStringId:[" << stringId.toStdString() << "]\n";

	if (stringId.isEmpty())
		return get().file.toString();

	else
		return "@" + file + ":" + stringId;
}