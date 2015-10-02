#include "stdafx.h"
#include "StopWatch.h"

JwPack::StopWatch::StopWatch()
{
	Reset();
}

JwPack::StopWatch::~StopWatch()
{
}

void JwPack::StopWatch::Reset()
{
	m_tp = std::chrono::system_clock::now();
}
