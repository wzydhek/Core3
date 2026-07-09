#include "HuntingTargetEntry.h"

HuntingTargetEntry::HuntingTargetEntry() {
	templatePrimary = "";
	templateSecondary = "";
}

HuntingTargetEntry::HuntingTargetEntry(const String& temp1, const String& temp2) {
	templatePrimary = temp1;
	templateSecondary = temp2;
}

String HuntingTargetEntry::getPrimary() {
	return templatePrimary;
}

String HuntingTargetEntry::getSecondary() {
	return templateSecondary;
}

int HuntingTargetEntry::compareTo(const HuntingTargetEntry& entry) const {
	if (templatePrimary.hashCode() < entry.templatePrimary.hashCode())
		return 1;
	else if (templatePrimary.hashCode() > entry.templatePrimary.hashCode())
		return -1;

	return 0;
}