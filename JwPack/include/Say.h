/**
@file
@brief debug string helper
@author keunho.yoo
*/
#pragma once
#include "JwPack.h"
#include <yvals.h> // __FUNCTIONW__
#include <cstdio>
#include <cstdlib>

#if defined(_DEBUG)
#define say_d(x, ...) { JwPack::Say(x, __VA_ARGS__); }
#define say_scope_d JwPack::SayScope func(__FUNCTIONW__);
#else
#define say_d(x, ...) __noop
#define say_scope_d __noop
#endif
#define say(x, ...) { JwPack::Say(x, __VA_ARGS__); }
#define say_scope JwPack::SayScope func(__FUNCTIONW__, false);

namespace JwPack
{
	/// print string
	inline void Say(const wchar_t* fmt, ...)
	{
		wchar_t buf[4096] = { 0, };
		va_list argptr;
		va_start(argptr, fmt);
		_vsnwprintf_s(buf, _countof(buf) - 1, fmt, argptr);
		OutputDebugString(buf);
		va_end(argptr);
	}

	inline void Say(const char* fmt, ...)
	{
		char buf[4096] = { 0, };
		va_list argptr;
		va_start(argptr, fmt);
		_vsnprintf_s(buf, _countof(buf) - 1, fmt, argptr);
		OutputDebugStringA(buf);
		va_end(argptr);
	}

	/// print string in scope
	class SayScope
	{
	public:
		SayScope(const wchar_t* scope, bool only_debug = true);
		~SayScope();
	private:
		bool m_only_debug;
		const wchar_t* m_scope;
	};
};