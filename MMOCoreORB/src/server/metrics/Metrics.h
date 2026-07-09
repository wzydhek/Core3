/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/core/MetricsManager.h"
#include "conf/ConfigManager.h"

namespace server {
namespace metrics {
	class Metrics {
		String path;
		bool active;

	public:
		Metrics();

		Metrics(const char* path);

		Metrics(String&& path);

		Metrics(const String& path);

		void publishMetrics(const String& name, const char* value, const char* type) const;

		void publishGauge(const String& name, const String& value) const;

		// TODO: Add a publish that can send a sample rate (a ratio of the
		// number of actual samples the server will use)
		void publishCounter(const String& name, const String& value) const;

		void publishTimer(const String& name, const String& value) const;

		void publishHist(const String& name, const String& value) const;

		void publishMeter(const String& name, const String& value) const;

		const String& getMetricsPath() const;

		bool areMetricsActive() const;

	protected:
		void setPath(const String& s);

	};
} // namespace metrics
} // namespace server

using namespace server::metrics;
