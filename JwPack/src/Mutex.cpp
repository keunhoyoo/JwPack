#include "stdafx.h"
#include "Mutex.h"
#include <mutex>

Mutex::Mutex()
{
	m_locker = CreateMutex(nullptr, false, nullptr);
}

void Mutex::Lock()
{
	WaitForSingleObject(m_locker, INFINITE);
}

bool Mutex::Lock(const int ms)
{
	DWORD ret = WaitForSingleObject(m_locker, ms);
	return ret == WAIT_OBJECT_0;
}

void Mutex::Unlock()
{
	ReleaseMutex(m_locker);
}
