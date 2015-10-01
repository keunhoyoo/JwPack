#pragma once
#include "JwPack.h"
#include "NonCopyable.h"
//#include "boost/noncopyable.hpp"

namespace JwPack
{
	// TODO
	//
	// 아래 singleton static 객체에 대한 소멸이후 
	// 다른 static 객체에서 singleton 참조에 대한 예외처리를 해야함.
	// 피닉스 싱글톤??
	
	template <typename T>
	class SingleTon : public NonCopyable
	{
	public:
		static T* GetInstance()
		{			
			static T instance;
			return &instance;
		}

	protected:
		SingleTon() {}
		virtual ~SingleTon() {}
	};
}