#include "ClientLogout.h"

ClientLogout::ClientLogout() : BaseMessage(20) {
	insertShort(0x01);
	insertInt(0x42FD19DD);
}