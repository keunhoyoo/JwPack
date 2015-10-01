#include "stdafx.h"
#include "Mutex.h"
#include "StopWatch.h"
#include <mutex>

Mutex::Mutex()
{
	std::mutex* mtx = new std::mutex();
	m_locker = mtx;
}

Mutex::~Mutex()
{
	delete ((std::mutex*)m_locker);
}

void Mutex::Lock()
{
	((std::mutex*)m_locker)->lock();
}

bool Mutex::Lock(const int ms)
{
	JwPack::StopWatch sw;
	while (((std::mutex*)m_locker)->try_lock() == false)
	{
		if (sw.Elapsed<>() > ms)
			return false;
		Sleep(1);
	}

	return true;
}

void Mutex::Unlock()
{
	((std::mutex*)m_locker)->unlock();
}
