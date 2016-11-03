//============================================================================
// Name        : ADA_T3_E6.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int pA[10*10 + 1];
	memset(pA, 0, sizeof(pA));
	int b[] = {1,2,3,4,5,6,7,8,9,10};
	int pB[10*10 + 1];
	memset(pB, 0, sizeof(pB));
	int pC[20*10+1];
	memset(pC, 0, sizeof(pC));
	for (int i = 0; i < 10; ++i)
	{
		pA[a[i]]++;
		pB[b[i]]++;
	}
	for (int i = 0; i < 10*10+1; ++i)
	{
		cout << pA[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 10*10+1; ++i)
	{
		cout << pB[i] << " ";
	}
	cout << endl;
	cout << endl;
	return 0;
}
