//============================================================================
// Name        : ADA_T2_E5.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int findK(int *A, int low, int high)
{
	while(low < high)
	{
		int mid = (high - low) / 2 + low;
		if (A[mid - 1] < A[mid] && A[mid] > A[mid+1])
			return mid;
		else if (A[mid - 1] < A[mid] && A[mid] < A[mid+1])
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	return - 1;
}

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,1};
	cout << findK(array, 0, 8) << endl;
	return 0;
}
