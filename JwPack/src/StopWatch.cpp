#include "stdafx.h"
#include "StopWatch.h"
#include <chrono>

typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<__int64, std::nano>> Clock;

namespace JwPack
{
	struct StopWatch::NanoSecond
	{
		static const unsigned __int64 TimeScale = 1LL;
	};
	struct StopWatch::MicroSecond
	{
		static const unsigned __int64 TimeScale = 1000LL;
	};
	struct StopWatch::MilliSecond
	{
		static const unsigned __int64 TimeScale = 1000000LL;
	};
	struct StopWatch::Second
	{
		static const unsigned __int64 TimeScale = 1000000000LL;
	};
}


JwPack::StopWatch::StopWatch()
	: m_tp(new Clock())
{
	Reset();
}

JwPack::StopWatch::~StopWatch()
{
	delete m_tp;
}

void JwPack::StopWatch::Reset()
{
	auto now = std::chrono::system_clock::now();
	*((Clock*)m_tp) = now;
}

template<typename Unit /*= MilliSecond*/>
unsigned __int64 JwPack::StopWatch::Elapsed()
{
	auto now = std::chrono::system_clock::now();
	auto ts = now - *((Clock*)m_tp);
	return ts.count() / Unit::TimeScale;
}

