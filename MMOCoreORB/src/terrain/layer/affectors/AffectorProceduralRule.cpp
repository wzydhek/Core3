#include "AffectorProceduralRule.h"

AffectorProceduralRule::AffectorProceduralRule() : affectorType(0) {
}

bool AffectorProceduralRule::isHeightTypeAffector() const {
	return affectorType & HEIGHTTYPE;
}

bool AffectorProceduralRule::isEnvoronmentTypeAffector() const {
	return affectorType & ENVIRONMENT;
}

int AffectorProceduralRule::getAffectorType() const {
	return affectorType;
}

bool AffectorProceduralRule::isEnabled() {
	return false;
}
