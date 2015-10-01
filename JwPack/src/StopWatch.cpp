#include "stdafx.h"
#include "StopWatch.h"
#include <chrono>

typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<__int64, std::nano>> Clock;

// const unsigned __int64 JwPack::StopWatch::Second = ;
// const unsigned __int64 JwPack::StopWatch::MilliSecond = ;
// const unsigned __int64 JwPack::StopWatch::MicroSecond = ;
// const unsigned __int64 JwPack::StopWatch::NanoSecond = 1LL;

namespace JwPack
 {
 	class StopWatch::NanoSecond::s = 1;
// 
// 	class StopWatch::MicroSecond
// 	{
// 		static const unsigned __int64 s = 1000LL;
// 	};
// 	class StopWatch::MilliSecond
// 	{
// 		static const unsigned __int64 s = 1000000LL;
// 	};
// 	class StopWatch::Second
// 	{
// 		static const unsigned __int64 s = 1000000000LL;
// 	};
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

// unsigned __int64 JwPack::StopWatch::Elapsed(unsigned __int64 Unit /*= MilliSecond*/)
// {
// 	auto now = std::chrono::system_clock::now();
// 	auto ts = now - *((Clock*)m_tp);
// 	return ts.count() / Unit;
// }
// 
// template<unsigned __int64 Unit /*= MilliSecond*/>
// unsigned __int64 JwPack::StopWatch::Elapsed()
// {
// 	auto now = std::chrono::system_clock::now();
// 	auto ts = now - *((Clock*)m_tp);
// 	return ts.count() / Unit;
// }

template<class T /*= MilliSecond*/>
unsigned __int64 JwPack::StopWatch::Elapsed()
{
	auto now = std::chrono::system_clock::now();
	auto ts = now - *((Clock*)m_tp);
	return ts.count() / T::s;
}

