#pragma once

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
	printf("1000ms sleep : %I64d s \n", sw.Elapsed(JwPack::StopWatch::Second));
	*/

	class StopWatch
	{
	public:
		StopWatch();
		~StopWatch();

		void Reset();

		struct NanoSecond;
		struct MicroSecond;
		struct MilliSecond;
		struct Second;

		template<typename Unit = MilliSecond>
		unsigned __int64 Elapsed();

	private:
		void* m_tp;
	};
}

