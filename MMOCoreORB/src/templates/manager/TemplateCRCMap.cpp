#include "TemplateCRCMap.h"

TemplateCRCMap::TemplateCRCMap() : HashTable<uint32, TemplateReference<SharedObjectTemplate*>>(16000) {
	setNullValue(nullptr);
}

int TemplateCRCMap::hash(const uint32& k) const {
	return k;
}

ClientTemplateCRCMap::ClientTemplateCRCMap() : HashTable<uint32, String>(16000) {
	setNullValue("");
}

int ClientTemplateCRCMap::hash(const uint32& k) const {
	return k;
}