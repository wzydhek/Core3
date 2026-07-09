#include "CommandQueueActionVector.h"

CommandQueueActionVector::CommandQueueActionVector() {
}

CommandQueueActionVector::CommandQueueActionVector(const CommandQueueActionVector& v) : SortedVector<CommandReference<CommandQueueAction*>>(v) {
}

CommandQueueActionVector& CommandQueueActionVector::operator=(const CommandQueueActionVector& v) {
	if (this == &v)
		return *this;

	SortedVector<CommandReference<CommandQueueAction*>>::operator=(v);

	return *this;
}

Object* CommandQueueActionVector::clone() {
	return ObjectCloner<CommandQueueActionVector>::clone(this);
}

Object* CommandQueueActionVector::clone(void* object) {
	return TransactionalObjectCloner<CommandQueueActionVector>::clone(this);
}