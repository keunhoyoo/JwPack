#include "stdafx.h"
#include "Say.h"


JwPack::SayScope::SayScope(const wchar_t* scope, bool only_debug /*= true*/)
	: m_scope(scope)
	, m_only_debug(only_debug)
{
	wchar_t msg[2048] = { 0, };
	swprintf_s(msg, L"%s [in] \n", m_scope);
	if (m_only_debug)
#ifdef _DEBUG
		JwPack::Say(L"%s", msg);
#endif
	else
		JwPack::Say(L"%s", msg);
}

JwPack::SayScope::~SayScope()
{
	wchar_t msg[2048] = { 0, };
	swprintf_s(msg, L"%s [out] \n", m_scope);
	if (m_only_debug)
#ifdef _DEBUG
		JwPack::Say(L"%s", msg);
#endif
	else
		JwPack::Say(L"%s", msg);
}


