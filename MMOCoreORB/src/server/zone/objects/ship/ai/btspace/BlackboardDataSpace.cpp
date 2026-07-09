#include "BlackboardDataSpace.h"

BlackboardDataSpace::BlackboardDataSpace() : Object(), data(NULL) {
}


BlackboardDataSpace::BlackboardDataSpace(const BlackboardDataSpace& in) : Object(), data(in.data) {
}

BlackboardDataSpace::BlackboardDataSpace(BlackboardDataSpace&& in) : BlackboardDataSpace() {
	swap(*this, in);
}

BlackboardDataSpace& BlackboardDataSpace::operator=(BlackboardDataSpace in) {
	swap(*this, in);
	return *this;
}

// define this as a member function to avoid ambiguous operator== overloads
bool BlackboardDataSpace::operator==(const BlackboardDataSpace& b) const {
	return *data == *b.data;
}
