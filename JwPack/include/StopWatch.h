/**
@file
@author keunho.yoo
*/
#pragma once
#include "JwPack.h"
#include <chrono>

namespace JwPack
{
	/*
	JwPack::StopWatch sw;

	sw.Reset();
	Sleep(300);
	printf("300ms sleep : %I64d ms \n", sw.Elapsed());

	sw.Reset();
	Sleep(1000);
	printf("1000ms sleep : %I64d ms \n", sw.Elapsed());

	sw.Reset();
	Sleep(1000);
	printf("1000ms sleep : %I64d s \n", sw.Elapsed<JwPack::StopWatch::Second>());
	*/

	class JWPACK_API StopWatch
	{
	public:
		StopWatch();
		~StopWatch();

		void Reset();

		struct NanoSecond
		{
			static const unsigned __int64 TimeScale = 1LL;
		};
		struct MicroSecond
		{
			static const unsigned __int64 TimeScale = 1000LL;
		};
		struct MilliSecond
		{
			static const unsigned __int64 TimeScale = 1000000LL;
		};
		struct Second
		{
			static const unsigned __int64 TimeScale = 1000000000LL;
		};

		template<typename Unit = MilliSecond>
		unsigned __int64 Elapsed()
		{
			return (std::chrono::system_clock::now() - m_tp).count() / Unit::TimeScale;
		}


	private:
		std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<__int64, std::nano>> m_tp;
	};
}

