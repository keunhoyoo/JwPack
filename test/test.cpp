// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	int** pp = new int*[2];

	for (int i = 0; i < 2; i++)
		pp[i] = new int[10];

	for (int i = 0; i < 2; i++)
		delete[] pp[i];

	//delete pp;

	return 0;
}

