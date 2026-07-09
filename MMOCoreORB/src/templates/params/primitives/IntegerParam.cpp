#include "IntegerParam.h"

IntegerParam::IntegerParam() : TemplateBase<int>(0) {
	setType(INTEGER);
}

IntegerParam::IntegerParam(const IntegerParam& p) : TemplateBase<int>(p) {
	setType(INTEGER);
}

IntegerParam& IntegerParam::operator=(int val) {
	create(val);

	return *this;
}

IntegerParam& IntegerParam::operator=(const IntegerParam& param) {
	if (this == &param) {
		return *this;
	}

	create(param.get());

	return *this;
}

String IntegerParam::toString() const {
	return String::valueOf(get());
}

bool IntegerParam::parse(engine::util::Chunk* source) {
	uint8 readCase = source->readByte();
	uint8 byte2 = source->readByte();

	if (readCase == 1 && byte2 == 0x20) {
		create(source->readInt());

		return true;
	} else if (readCase == 2 && byte2 == 0x20) {
		/*int size = source->getUnsignedInt();

		QVector<IntegerParam> params;

		for (int i = 0; i < size; ++i) {
			int unknown = source->getUnsignedInt();

			IntegerParam param;

			if (param.parse(source))
				params.push_back(param);
		}*/

		IffStream* iffStream = source->getIffStream();

		StringBuffer msg;
		msg << "unhandled IntegerParam type! in " << iffStream->getFileName();

		Logger::console.info(msg.toString());

	} /* else {
		 create(0);
	 }*/

	return false;
}