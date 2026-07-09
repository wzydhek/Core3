#include "MySqlResultSet.h"


MySqlResultSet::MySqlResultSet(MYSQL* db, MYSQL_RES* res) : row(nullptr) {
	mysql = db;
	result = res;
}

MySqlResultSet::~MySqlResultSet() {
	mysql_free_result(result);
}

bool MySqlResultSet::next() {
	return (row = mysql_fetch_row(result)) != nullptr;
}

bool MySqlResultSet::getBoolean(int index) {
	return atoi(row[index]);
}

int MySqlResultSet::getInt(int index) {
	return atoi(row[index]);
}

sys::uint32 MySqlResultSet::getUnsignedInt(int index) {
	return (sys::uint32)strtoul(row[index], nullptr, 0);
}

sys::int64 MySqlResultSet::getLong(int index) {
	return Long::valueOf(row[index]);
}

sys::uint64 MySqlResultSet::getUnsignedLong(int index) {
	return Long::unsignedvalueOf(row[index]);
}

float MySqlResultSet::getFloat(int index) {
	return atof(row[index]);
}

char* MySqlResultSet::getString(int index) {
	return row[index];
}

sys::uint64 MySqlResultSet::getRowsAffected() {
	return mysql_affected_rows(mysql);
}

sys::uint64 MySqlResultSet::getLastAffectedRow() {
	return mysql_insert_id(mysql);
}

sys::uint64 MySqlResultSet::size() {
	return mysql_num_rows(result);
}