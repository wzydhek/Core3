#include "TreeDirectory.h"

TreeDirectory::TreeDirectory() : SortedVector<Reference<TreeFileRecord*>>() {
	setNoDuplicateInsertPlan();
}

TreeDirectory::TreeDirectory(const TreeDirectory& d) : SortedVector<Reference<TreeFileRecord*>>(d) {
	setNoDuplicateInsertPlan();
}

TreeDirectory& TreeDirectory::operator=(const TreeDirectory& d) {
	if (this == &d)
		return *this;

	SortedVector<Reference<TreeFileRecord*>>::operator=(d);

	return *this;
}

int TreeDirectory::compare(const Reference<TreeFileRecord*>& o1, const Reference<TreeFileRecord*>& o2) const {
	return o1->compareTo(*o2.get());
}

int TreeDirectory::compare(const Reference<TreeFileRecord*>& o1, const String& fileName) const {
	return o1->compareTo(fileName);
}

int TreeDirectory::find(const String& fileName) const {
	int l = 0, r = Vector<Reference<TreeFileRecord*>>::elementCount - 1;
	int m = 0, cmp = 0;

	while (l <= r) {
		m = (l + r) / 2;

		const Reference<TreeFileRecord*>& obj = Vector<Reference<TreeFileRecord*>>::elementData[m];
		cmp = compare(obj, fileName);

		if (cmp == 0)
			return m;
		else if (cmp > 0)
			l = m + 1;
		else
			r = m - 1;
	}

	return -1;
}