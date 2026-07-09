#include "BlackboardData.h"

BlackboardData::AbstractData::~AbstractData() {
}

BlackboardData::BlackboardData() : Object(), data(NULL) {
}

BlackboardData::BlackboardData(const BlackboardData& in) : Object(), data(in.data) {
}

BlackboardData::BlackboardData(BlackboardData&& in) : BlackboardData() {
	swap(*this, in);
}

BlackboardData& BlackboardData::operator=(BlackboardData in) {
	swap(*this, in);
	return *this;
}

// define this as a member function to avoid ambiguous operator== overloads
bool BlackboardData::operator==(const BlackboardData& b) const {
	return *data == *b.data;
}