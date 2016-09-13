//============================================================================
// Name        : ADA_T2_E6.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int findK(int *A, int low, int high)
{
	int mid = (high - low) / 2 + low;
	if (A[low] < A[mid] && A[mid] < A[high])
		return -1;

	while(low < high)
	{
		int mid = (high - low) / 2 + low;
		//cout << "MID = " << mid << endl;
		if (A[mid - 1] < A[mid] && A[mid] > A[mid+1])
			return mid;
		//else if (A[mid - 1] < A[mid] && A[mid] < A[mid+1])
		else if (A[low] > A[high] && A[mid] < A[low])
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	return -1;
}


int main()
{
	int array[] = {25, 1, 3, 4, 5, 7, 10, 14, 15, 16, 19,20};
	int k;
	cin >> k;
	int bP = (findK(array, 0, 11) + k) % 12;
	cout << array[bP] << endl;
	return 0;
}
