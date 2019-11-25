#include "Timer.h"

Timer::Timer(const char* name)
	: m_Name(name), m_Stopped(false)
{
	m_StartTimepoint = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	if (!m_Stopped)
	{
		Stop();
	}
}

void Timer::Stop()
{
	auto endTimepoint = std::chrono::high_resolution_clock::now();

	long long start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_StartTimepoint).time_since_epoch().count();
	long long end = std::chrono::time_point_cast<std::chrono::nanoseconds>(endTimepoint).time_since_epoch().count();

	std::cout << m_Name << ": " << (end - start) << "ns\n";

	m_Stopped = true;
}
