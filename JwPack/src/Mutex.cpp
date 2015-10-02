#include "stdafx.h"
#include "Mutex.h"
#include "StopWatch.h"


void JwPack::Mutex::Lock()
{
	m_mtx.lock();
}

bool JwPack::Mutex::Lock(const int ms)
{
	JwPack::StopWatch sw;
	while (m_mtx.try_lock() == false)
	{
		if (sw.Elapsed<JwPack::StopWatch::MilliSecond>() > ms)
			return false;
		Sleep(1);
	}

	return true;
}

void JwPack::Mutex::Unlock()
{
	m_mtx.unlock();
}
