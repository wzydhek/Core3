#pragma once

#include "engine/engine.h"
#include "server/zone/objects/ship/ai/ShipAiAgent.h"

class ShipObjectTimerTask : public Task, public Logger {
	public:
		enum Timers : int {
			MIN = 0,
			MID = 1,
			MAX = 2,
			SIZE = 3
		};

		enum Intervals : int {
			TIME_MIN = 200,
			TIME_MID = 1000,
			TIME_MAX = 2000,
			TIME_SLEEP = 5000
		};

		static const int ITERATOR_MID = TIME_MID / TIME_MIN;
		static const int ITERATOR_MAX = TIME_MAX / TIME_MIN;
		static const int SCHEDULE_MIN = TIME_MIN * 0.125f;
		static const int SCHEDULE_MAX = TIME_MIN;

	protected:
		Vector<ManagedReference<ShipObject*>> shipVector;
		Vector<ManagedReference<ShipAiAgent*>> agentVector;
		Vector<ManagedWeakReference<ShipObject*>> queueVector;

		Vector<uint64> timers;
		Vector<uint32> deltas;

		uint64 startTime;
		uint32 iterator;
		uint32 priority;
		uint32 taskCrc;

		HashSet<ShipObject*> shipSet;
		mutable ReadWriteLock mutex;

	public:
		ShipObjectTimerTask(const String& taskQueueName);

		void addShip(ShipObject* ship);

		void run();

		uint32 getTaskCrc() const;

	private:
		void updateTimers();

		uint32 getDeltaTime(int index) const;

		bool getAsyncPriority(int iteratorMax, int index) const;

		uint32 getScheduleInterval();

		void updateAgents();

		void updateShips();

		void updateVectors();

		bool isShipValid(ShipObject* ship) const;

		String toDebugString(const String& message) const;
	};
