#include "GuildList.h"

GuildList::GuildList() : VectorMap<uint32, ManagedReference<GuildObject*>>() {
}