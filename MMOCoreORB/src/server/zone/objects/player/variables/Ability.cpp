#include "Ability.h"

Ability::Ability() : Object() {
}

Ability::Ability(const String& name) : Object() {
	abilityName = name;
}

Ability::Ability(const Ability& a) : Object() {
	abilityName = a.abilityName;
}

Ability& Ability::operator=(const Ability& a) {
	if (this == &a)
		return *this;

	abilityName = a.abilityName;

	return *this;
}

int Ability::compareTo(const Ability& a) {
	return abilityName.compareTo(a.abilityName);
}

const String& Ability::getAbilityName() const {
	return abilityName;
}

void Ability::setAbilityName(const String& name) {
	abilityName = name;
}

bool Ability::toBinaryStream(ObjectOutputStream* stream) {
	abilityName.toBinaryStream(stream);

	return true;
}