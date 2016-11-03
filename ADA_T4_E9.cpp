//============================================================================
// Name        : ADA_T4_E9.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int path[] = {100, 8, 6, 34, 6, 7, 9 ,11, 3};
	const int size = sizeof(path)/sizeof(int);
	int maximum[size];
	int from[size];
	maximum[0] = path[0];
	from[0] = 0;
	from[1] = 1;
	maximum[1] = path[1];

	for (int i = 2; i < size; ++i)
	{
		if (maximum[i - 2] + path[i] > maximum[i-1])
		{
			maximum[i] = maximum[i - 2] + path[i];
			from[i] = i;
		}
		else
		{
			maximum[i] = maximum[i-1];
			from[i] = from[i-1];
		}
	}
	int i = size - 1;
	while (i >= 0)
	{
		if (from[i] == i)
		{
			cout << i << " ";
			i -= 2;
		}
		else
			i = from[i];
	}
	cout << "MAX WEIGHT = " << maximum[size-1] << endl;
	return 0;
}
