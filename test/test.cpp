// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../JwPack/include/Align.h"
#include "../JwPack/include/ErrDesc.h"

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

int _tmain(int argc, _TCHAR* argv[])
{
	*((int*)0) = 0;

	setlocale(LC_ALL, "");

	AlignTest();
	ErrDescTest();

	return 0;
}

