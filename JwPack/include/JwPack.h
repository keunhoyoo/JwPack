#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#ifndef ASSERT
#include <cassert>
#define ASSERT(x) assert(x)
#endif

