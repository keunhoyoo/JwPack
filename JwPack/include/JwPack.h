#pragma once

#if defined (_WIN32) || defined (WIN32) || defined(_WIN64) || defined(WIN64)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#	ifdef JWPACK_EXPORT
#		define JWPACK_API __declspec(dllexport)
#	else
#		define JWPACK_API __declspec(dllimport)
#	endif
#else
#	define JWPACK_API
#endif

// template export
#pragma warning(disable:4251)

#ifndef ASSERT
#include <cassert>
#define ASSERT(x) assert(x)
#endif



#include "NonCopyable.h"
