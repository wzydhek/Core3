#include "ApplyDiseaseCommand.h"

ApplyDiseaseCommand::ApplyDiseaseCommand(const String& name, ZoneProcessServer* server) : DotPackCommand(name, server) {
	skillName = "applydisease";
}
