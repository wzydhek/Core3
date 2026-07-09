#include "StringParam.h"

StringParam::StringParam() : TemplateBase<String>(String("")) {
	setType(STRING);
}

StringParam::StringParam(const String& val) : TemplateBase<String>(val) {
	setType(STRING);
}

StringParam::StringParam(const StringParam& p) : TemplateBase<String>(p.get()) {
	setType(STRING);
}

String StringParam::toString() const {
	// return get();
	StringBuffer stream;

	stream << "\"" << get() << "\"";

	return stream.toString();
}

bool StringParam::parse(engine::util::Chunk* source) {
	int readCase = source->readByte();

	if (readCase == 1) {
		String val;
		source->readString(val);

		// std::cout << "read case 1:[" << val.toStdString() << "]\n";
		create(val);

		return true;
	} /* else if (readCase == 0) {
		 create("");
		 std::cout << "read case 0\n";
	 } else {
		 throw Exception("Unknown case in StringParam::parse(Chunk* dat)");
	 }*/

	return false;
}

StringParam& StringParam::operator=(const String& val) {
	create(val);

	return *this;
}

StringParam& StringParam::operator=(const StringParam& val) {
	if (this == &val) {
		return *this;
	}

	setType(STRING);

	TemplateBase<String>::operator=(val);

	return *this;
}

String& StringParam::operator-=(const String& val) {
	return value;
}