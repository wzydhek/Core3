#include "HarvesterSetupSharedNetworkMessage.h"

HarvesterSetupSharedNetworkMessage::HarvesterSetupSharedNetworkMessage(InstallationObject* inso) : ObjectControllerMessage(inso->getObjectID(), 0x1B, 0x022B) {
}