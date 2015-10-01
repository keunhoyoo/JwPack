#include "stdafx.h"
#include "Mutex.h"
#include "StopWatch.h"
#include <mutex>

JwPack::Mutex::Mutex()
{
	m_mtx = new std::mutex();
}

JwPack::Mutex::~Mutex()
{
	delete m_mtx;
}

void JwPack::Mutex::Lock()
{
	m_mtx->lock();
}

bool JwPack::Mutex::Lock(const int ms)
{
	JwPack::StopWatch sw;
	while (m_mtx->try_lock() == false)
	{
		if (sw.Elapsed<>() > ms)
			return false;
		Sleep(1);
	}

	return true;
}

void JwPack::Mutex::Unlock()
{
	m_mtx->unlock();
}
