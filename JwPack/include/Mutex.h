/**
@file
@author keunho.yoo
*/
#pragma once
#include "JwPack.h"
#include <mutex>

namespace JwPack
{
	class JWPACK_API Mutex : JwPack::NonCopyable
	{
	public:
		virtual void Lock();
		virtual bool Lock(const int ms);
		virtual void Unlock();

		std::mutex m_mtx;
	};

	class ScopeMutex : JwPack::NonCopyable
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

