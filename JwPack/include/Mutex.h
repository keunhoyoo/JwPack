#pragma once
#include "JwPack.h"

namespace std
{
	class mutex;
}

namespace JwPack
{
	class Mutex : JwPack::NonCopyable
	{
	public:
		Mutex();
		virtual ~Mutex();

		virtual void Lock();
		virtual bool Lock(const int ms);
		virtual void Unlock();

		std::mutex* m_mtx;
	};

	class ScopeMutex
	{
	public:
		ScopeMutex(Mutex* mutex) : m_mutex(mutex)
		{
			m_mutex->Lock();
		}

		~ScopeMutex()
		{
			m_mutex->Unlock();
		}

		Mutex* m_mutex;
	};
}

