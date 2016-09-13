//============================================================================
// Name        : ADA_T2_E3.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


void printArray(int *A, int size)
{
	for (int i = 0; i < size; ++i)
		cout << A[i] << " ";
	cout << endl;
}

int findMedian(int *A, int *B, int n, int low, int high)
{
	if (low > high)
	{
		return -1;
	}
	else
	{
		int k = floor((low + high) / 2);
		if (k == n && A[n] <= B[0])
			return A[n];
		else if (k < n && B[n-k] <= A[k] <= B[n-k+1])
			return A[k];
		else if (A[k] > B[n-k+1])
			return findMedian(A, B, n, low, k-1);
		else
			return findMedian(A, B, n, k+1, high);
	}
}

int twoArrayMedian(int *X, int* Y, int size)
{
	int median = findMedian(X, Y, size, 0, size);
	if (median == -1)
		median = findMedian(Y, X, size, 0, size);
	return median;
}

int findMedian2(int *A, int *B, int n, int low, int high)
{
	if (low > high)
	{
		return -1;
	}
	else
	{
		int k = floor((low + high) / 2);
		if (k == n && A[n] <= B[1])
		{
			return A[n];
		}
		else if (k < n && B[n-k] <= A[k] &&  A[k] <= B[n-k+1])
		{
			return A[k];
		}
		else if (A[k] > B[n-k+1])
		{
			return findMedian2(A, B, n, low, k-1);
		}
		else
		{
			return findMedian2(A, B, n, k+1, high);
		}
	}
}

int twoArrayMedian2(int *X, int* Y, int size)
{
	int median = findMedian2(X, Y, size, 1, size);
	if (median == -1)
		median = findMedian2(Y, X, size, 1, size);
	return median;
}

int main()
{
	int A1[] = {0,7,2,9,4,8,12,20,15,25};
	sort(A1, A1+9);
	printArray(A1, 10);
	int A2[] = {0,8,14,3,11,24,21,5,1, 6};
	sort(A2, A2+9);
	printArray(A2, 10);
	int k;
	while (true)
	{
		cin >> k;


		cout << twoArrayMedian2(A1, A2, k) << endl;
	}

	return 0;
}
