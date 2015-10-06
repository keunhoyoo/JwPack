// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../JwPack/include/Align.h"
#include "../JwPack/include/ErrDesc.h"
#include "../JwPack/include/StopWatch.h"
#include "../JwPack/include/Mutex.h"

#include <conio.h>

void AlignTest()
{
	int i = 13205298;
	JwPack::Align::RoundDown(i, 234);
	ASSERT(i % 234 == 0);

	i = 138;
	JwPack::Align::RoundUp(i, 4);
	ASSERT(i % 4 == 0);
}

void ErrDescTest()
{
	auto ed = JwPack::ErrDesc::GetInstance();

	wprintf(L"Win32 error 2 => %s \n", ed->GetWin32ErrorMsg(2));
	wprintf(L"DShow error 0x80070004 => %s \n", ed->GetDShowErrorMsg(0x80070004));
	wprintf(L"HRESULT error 0x8007000e => %s \n", ed->GetHResultErrorMsg(0x8007000e));
	wprintf(L"errno error -3 => %s \n", ed->GeterrnoMsg(-3));
}

void MutexTest()
{
	JwPack::Mutex mtx;

	{
		JwPack::ScopeMutex sm(&mtx);
	}

}

void StopWatchTest()
{
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
}

int _tmain(int argc, _TCHAR* argv[])
{
	//*((int*)0) = 0;

	setlocale(LC_ALL, "");

	AlignTest();
	ErrDescTest();

	StopWatchTest();

	return 0;
}

