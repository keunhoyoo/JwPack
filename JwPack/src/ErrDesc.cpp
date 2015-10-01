#include "stdafx.h"
#include "ErrDesc.h"
#include <comdef.h>
#include <errors.h>

#pragma comment(lib, "quartz.lib")


const wchar_t* JwPack::ErrDesc::GetWin32ErrorMsg(const unsigned long error_code)
{
	return GetHResultErrorMsg(HRESULT_FROM_WIN32(error_code));
}

const wchar_t* JwPack::ErrDesc::GetHResultErrorMsg(const HRESULT hr)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	_com_error err(hr);
	wcscpy_s(m_str_buffer, err.ErrorMessage());
	return m_str_buffer;
}

const wchar_t* JwPack::ErrDesc::GetDShowErrorMsg(const HRESULT hr)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	auto len = AMGetErrorText(hr, m_str_buffer, kStrBufferLen);
	if (m_str_buffer[len - 2] == L'\r')// && m_str_buffer[len - 1] == L'\n')
  		m_str_buffer[len - 2] = L'\0';
	return m_str_buffer;
}

const wchar_t* JwPack::ErrDesc::GeterrnoMsg(const int _errno)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	_wcserror_s(m_str_buffer, kStrBufferLen, _errno);
	return m_str_buffer;
}
