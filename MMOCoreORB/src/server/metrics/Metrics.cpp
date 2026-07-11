#include "Metrics.h"

Metrics::Metrics(const char* path) : path(path) {
	active = ConfigManager::instance()->shouldUseMetrics();
}

Metrics::Metrics(String&& path) : path(std::move(path)) {
	active = ConfigManager::instance()->shouldUseMetrics();
}

Metrics::Metrics(const String& path) : path(path) {
	active = ConfigManager::instance()->shouldUseMetrics();
}

void Metrics::publishMetrics(const String& name, const char* value, const char* type) const {
	if (!active)
		return;

	MetricsManager::Result result = MetricsManager::instance()->publish(String(path + "." + name).toCharArray(), value, type);

	static Logger logger("Metrics", Logger::INFO);

	switch (result) {
		case MetricsManager::NO_CONNECTION:
			logger.debug("Metrics failed to get connection.");
			return;
		case MetricsManager::SOCKET_EXCEPTION:
			logger.debug("Metrics encountered a socket exception.");
			return;
		case MetricsManager::GENERAL_ERROR:
			logger.debug("Metrics encountered a general error.");
			return;
		case MetricsManager::SUCCESS:
			logger.debug("Metrics success!");
		default:
			return;
	};
}

void Metrics::publishGauge(const String& name, const String& value) const {
	publishMetrics(name, value.toCharArray(), "g");
}

// TODO: Add a publish that can send a sample rate (a ratio of the
// number of actual samples the server will use)
void Metrics::publishCounter(const String& name, const String& value) const {
	publishMetrics(name, value.toCharArray(), "c");
}

void Metrics::publishTimer(const String& name, const String& value) const {
	publishMetrics(name, value.toCharArray(), "ms");
}

void Metrics::publishHist(const String& name, const String& value) const {
	publishMetrics(name, value.toCharArray(), "h");
}

void Metrics::publishMeter(const String& name, const String& value) const {
	publishMetrics(name, value.toCharArray(), "m");
}

const String& Metrics::getMetricsPath() const {
	return path;
}

bool Metrics::areMetricsActive() const {
	return active;
}

void Metrics::setPath(const String& s) {
	path = s;
}