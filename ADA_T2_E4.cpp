//============================================================================
// Name        : ADA_T2_E4.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Result
{
public:
	int lowIndex;
	int highIndex;
	double maxMultiplication;
};

Result maxProduct(double *nums, int size)
{
	double *max = new double[size];
	double *min = new double[size];
	int *fromMax = new int[size];
	int *fromMin = new int[size];
	Result r;
	max[0] = min[0] = nums[0];
	fromMax[0] = 0;
	fromMin[0] = 0;
	r.maxMultiplication = nums[0];

	for(int i=1; i < size; i++)
	{
		if(nums[i]>0)
		{
			max[i]=std::max(nums[i], max[i-1]*nums[i]);
			if (std::max(nums[i], max[i-1]*nums[i]) == nums[i])
				fromMax[i] = i;
			else
				fromMax[i] = fromMax[i-1];
			min[i]=std::min(nums[i], min[i-1]*nums[i]);
			if (std::min(nums[i], min[i-1]*nums[i]) == nums[i])
				fromMin[i] = i;
			else
				fromMin[i] = fromMin[i-1];
		}
		else
		{
			max[i]=std::max(nums[i], min[i-1]*nums[i]);
			if (std::max(nums[i], min[i-1]*nums[i]) == nums[i])
				fromMax[i] = i;
			else
				fromMax[i] = fromMin[i-1];
			min[i]=std::min(nums[i], max[i-1]*nums[i]);
			if (std::min(nums[i], max[i-1]*nums[i]) == nums[i])
				fromMin[i] = i;
			else
				fromMin[i] = fromMax[i-1];
		}

		if (std::max(r.maxMultiplication, max[i]) == max[i])
		{
			r.lowIndex = fromMax[i];
			r.highIndex = i;
		}
		r.maxMultiplication = std::max(r.maxMultiplication, max[i]);
	}
	delete [] max;
	delete [] min;
	delete [] fromMax;
	delete [] fromMin;

	return r;
}

int main()
{
	int T;
	int N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		double array[N];

		for (int i = 0; i < N; ++i)
			cin >> array[i];

		Result r = maxProduct(array, N);
		cout << "La subsecuencia ";
		for (int i = r.lowIndex; i <= r.highIndex; ++i)
			cout << array[i] << " ";
		cout << "es la de múltiplicación máxima con un valor de " << r.maxMultiplication << endl;
	}
	return 0;
}
