/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#include "StringIdParameter.h"

#include "StringId.h"

StringIdParameter::StringIdParameter(const StringIdParameter& par) : Object(), Serializable() {
	addSerializableVariables();

	pointerParameter = par.pointerParameter;
	stringID = par.stringID;
	customName = par.customName;
}

StringIdParameter::StringIdParameter() : Serializable() {
	addSerializableVariables();
}

#ifdef CXX11_COMPILER
StringIdParameter::StringIdParameter(StringIdParameter&& par) : Object(), Serializable(),
		pointerParameter(par.pointerParameter), stringID(std::move(par.stringID)),
		customName(std::move(par.customName)) {
	addSerializableVariables();
}
#endif

void StringIdParameter::set(const StringId* sid) {
	set(*sid);
}

void StringIdParameter::set(const StringId& sid) {
	clear();

	stringID = sid;
}

void StringIdParameter::addSerializableVariables() {
	addSerializableVariable("stringID", &stringID);
	addSerializableVariable("pointerParameter", &pointerParameter);
	addSerializableVariable("customName", &customName);
}

StringIdParameter& StringIdParameter::operator=(const StringIdParameter& par) {
	if (this == &par)
		return *this;

	pointerParameter = par.pointerParameter;
	stringID = par.stringID;
	customName = par.customName;

	return *this;
}

#ifdef CXX11_COMPILER
StringIdParameter& StringIdParameter::operator=(StringIdParameter&& par) {
	if (this == &par)
		return *this;

	pointerParameter = par.pointerParameter;
	stringID = std::move(par.stringID);
	customName = std::move(par.customName);

	return *this;
}
#endif

void StringIdParameter::clear() {
	stringID.clear();
	pointerParameter = 0;
}

void StringIdParameter::set(uint64 oid) {
	clear();

	pointerParameter = oid;
}

void StringIdParameter::set(const String& file, const String& id) {
	clear();

	stringID.setStringId(file, id);
}

void StringIdParameter::set(const UnicodeString& us) {
	clear();

	customName = us;
}

void StringIdParameter::set(const String& cs) {
	clear();

	customName = UnicodeString(cs);
}

void StringIdParameter::set(const char* cstr) {
	clear();

	customName = UnicodeString(cstr);
}

uint32 StringIdParameter::size() const {
	return sizeof(pointerParameter) + stringID.size();
}

uint64 StringIdParameter::getPointerParameter() const {
	return pointerParameter;
}

const UnicodeString& StringIdParameter::getUnicodeParameter() const {
	return customName;
}

String StringIdParameter::getDisplayedName() const {
	if (customName.isEmpty()) {
		return stringID.getFullPath();
	} else {
		return customName.toString();
	}
}

const String& StringIdParameter::getFileParameter() const {
	return stringID.getFile();
}

const String& StringIdParameter::getStringIDParameter() const {
	return stringID.getStringID();
}

void server::zone::objects::scene::variables::to_json(nlohmann::json& j, const StringIdParameter& p) {
	j["stringID"] = p.stringID;
	j["pointerParameter"] = p.pointerParameter;
	j["customName"] = p.customName;
}
