#include <iostream>
#include <chrono>
using namespace std;

class Stoper
{
private:
	chrono::steady_clock::time_point  startTime, stopTime;

public:
	Stoper() {}
	void setStartTime() {
		startTime = chrono::high_resolution_clock::now();
	}
	void setStopTime() {
		stopTime = chrono::high_resolution_clock::now();
	}

	long long getStopwachTime(int t /*1-microsecond 2-milisecond* other-second*/) {
		long long dt;
		switch (t) {
		case 1: {
			chrono::microseconds t;
			t = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
			dt = t.count();
			break;
		}
		case 2: {
			chrono::milliseconds t;
			t = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);
			dt = t.count();
			break;
		}
		default: {
			chrono::seconds t;
			t = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);
			dt = t.count();

			break;
		}
		}
		return dt;
	}
};