#pragma once

typedef void* SyncLock;
class ThreadLock
{
public:
	virtual void Lock() = 0;
	virtual bool Lock(const int ms) = 0;
	virtual void Unlock() = 0;

protected:
	SyncLock m_locker;
};

class Mutex : public ThreadLock
{
public:
	Mutex();

	virtual void Lock();
	virtual bool Lock(const int ms);
	virtual void Unlock();
};

