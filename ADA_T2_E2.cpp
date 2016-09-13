//============================================================================
// Name        : ADA_T2_E2.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int partition(int *A, int p, int r)
{
	int x = A[r];

	int i = p - 1;

	for (int j = p; j <= r - 1; ++j)
		if (A[j] <= x)
		{
			++i;
			std::swap(A[i], A[j]);
		}

	std::swap(A[i + 1], A[r]);

	return i + 1;
}

void insertionSort(int *A, int l, int u)
{
	for (int i = l + 1; i <= u; ++i)
	{
		for (int j = i; j > l; --j)
			if (A[j] < A[j-1])
			{
				std::swap(A[j],A[j-1]);
			}
	}
}

int SelectPro(int *A, int p, int r, int z)
{
	if (p == r)
	{
		return A[p];
	}

	int size = r - p + 1;

	int *array = new int[size/5 + (size % 5)];
	int index = 0;

	for (int i = p; i <= r; i += 5)
	{
		if (i + 4 <= r)
		{
			insertionSort(A, i, i + 4);
			array[index++] = A[i+2];
		}
		else
		{
			insertionSort(A, i, r);
			int nSize = r - i + 1;
			array[index++] = A[i + (nSize / 2) - (nSize % 2 == 0)];
		}
	}

	int median = SelectPro(array, 0, index - 1, index / 2 + (index % 2));

	int q;

	for (int i = p; i <= r; ++i)
		if (A[i] == median)
		{
			swap(A[i], A[r]);
			q = partition(A, p, r);
			break;
		}

	int k = q - p + 1;

	delete [] array;

	if (z == k)
	{
		return A[q];
	}
	else if (z < k)
	{
		return SelectPro(A, p, q - 1, z);
	}
	else
	{
		return SelectPro(A, q + 1, r, z - k);
	}
}

int main()
{
	srand(time(NULL));
	//int array[] = {24, 3, 9, 4, 8, 12, 20, 15, 10};
	int array[] = {7, 3, 9, 4, 8, 12, 20, 15, 25};
	size_t arraySize = sizeof(array)/sizeof(int);
	int r = SelectPro(array, 0, arraySize - 1, 5);
	cout << "MEDIAN IS = " << r << endl;

	int diffs[arraySize];
	for (int i = 0; i < arraySize; ++i)
	{
		diffs[i] = abs(array[i] - r);
		//cout << "ELEM = " << array[i] << " " << endl;
		//cout << "DIFF = " << diffs[i] << " " << endl;
	}

	int k;
	cin >> k;
	int esimo = SelectPro(diffs, 0, arraySize - 1, k + 1);
	cout << "KESIMO = " << esimo << endl;
	for (int i = 0; i < arraySize; ++i)
	{
		//cout << "DIFFS{i} =" << diffs[i] << endl;
		if (array[i] != r && abs(array[i] - r) <= esimo)
			cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}


/*int randomizedPartition(int *A, int p, int r)
{
	int i = p + rand() % ((r + 1) - p);
	std::swap(A[r], A[i]);
	return partition(A, p, r);
}

int randomizedSelect(int *A, int p, int r, int i)
{
	if (p == r)
		return A[p];

	int q = randomizedPartition(A, p, r);
	int k = q - p + 1;

	if (i == k)
		return A[q];
	else if (i < k)
		return randomizedSelect(A, p, q - 1, i);
	else
		return randomizedSelect(A, q + 1, r, i - k);
}*/
