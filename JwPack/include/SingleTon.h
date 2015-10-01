#pragma once
#include "JwPack.h"
#include "NonCopyable.h"
//#include "boost/noncopyable.hpp"

namespace JwPack
{
	// TODO
	//
	// �Ʒ� singleton static ��ü�� ���� �Ҹ����� 
	// �ٸ� static ��ü���� singleton ������ ���� ����ó���� �ؾ���.
	// �Ǵн� �̱���??
	
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