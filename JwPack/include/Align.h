/**
@file
@author keunho.yoo
*/
#pragma once
#include "JwPack.h"

namespace JwPack
{
	/// multiple adjustments
	class Align
	{
	public:
		template<class T>
		static void RoundUp(T& value, const int multipleby)
		{
			value += (multipleby - (value % multipleby)) % multipleby;
		}

		template<class T>
		static void RoundDown(T& value, const int multipleby)
		{
			value -= ((value % multipleby) + multipleby) % multipleby;
		}
	};
}