#pragma once

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

namespace JwPack
{
	struct CrtDbgLeak
	{
		CrtDbgLeak()
		{
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		}
	};
}

static JwPack::CrtDbgLeak cdl;