/*
 * TreeDirectory.h
 *
 *  Created on: Apr 8, 2011
 *      Author: crush
 */

#pragma once

#include "TreeFileRecord.h"

namespace tre3 {
class TreeDirectory : public SortedVector<Reference<TreeFileRecord*>> {
public:
	TreeDirectory();

	TreeDirectory(const TreeDirectory& d);

	TreeDirectory& operator=(const TreeDirectory& d);

	int compare(const Reference<TreeFileRecord*>& o1, const Reference<TreeFileRecord*>& o2) const;

	int compare(const Reference<TreeFileRecord*>& o1, const String& fileName) const;

	int find(const String& fileName) const;
};
} // namespace tre3

using namespace tre3;