#include "VuidString.h"

VuidString::VuidString() : String() {
}

VuidString::~VuidString() {
}

VuidString::VuidString(const String& val) : String(val) {
}

VuidString::VuidString(const char* str) : String(str) {
}

VuidString::VuidString(const VuidString& val) : String(val) {
}

int VuidString::compareTo(const VuidString& str) const {
	if (beginsWith(str))
		return 0;

	return String::compareTo((String)str);
}