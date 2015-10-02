/**
@file
@author keunho.yoo
*/
#pragma once
#include "JwPack.h"
#include "SingleTon.h"
#include <string>
#include <mutex>

namespace JwPack
{
	/*
	auto ed = JwPack::ErrDesc::GetInstance();

	wprintf(L"Win32 error 2 => %s \n", ed->GetWin32ErrorMsg(2));
	wprintf(L"DShow error 0x80070004 => %s \n", ed->GetDShowErrorMsg(0x80070004));
	wprintf(L"HRESULT error 0x8007000e => %s \n", ed->GetHResultErrorMsg(0x8007000e));
	wprintf(L"errno error -3 => %s \n", ed->GeterrnoMsg(-3));	
	*/

	class ErrDesc : public SingleTon<ErrDesc>
	{
	public:
		const wchar_t* GetWin32ErrorMsg(const unsigned long error_code);
		const wchar_t* GetHResultErrorMsg(const HRESULT hr);
		const wchar_t* GetDShowErrorMsg(const HRESULT hr);
		const wchar_t* GeterrnoMsg(const int _errno);

	private:
		std::mutex m_mutex;
		static const int kStrBufferLen = 1024;
		wchar_t m_str_buffer[kStrBufferLen];
	};
}

