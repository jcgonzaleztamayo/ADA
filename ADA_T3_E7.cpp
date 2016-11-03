//============================================================================
// Name        : ADA_T3_E7.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <boost/math/constants/constants.hpp>
#include <math.h>
#include <complex>
using namespace boost::math::double_constants;
using namespace std;

vector<long double> recursiveFFT(vector<int> a)
{
	int n = a.size();
	if (n == 1)
		return a;

	complex<long double> wn(cos(2*pi/n), sin((2*pi)/n));
	complex<long double> ww(1);

	vector<long double> a0, a1;
	a0.reserve(n/2);
	a1.reserve(n/2);

	for(int i = 0; i < n; ++i)
	{
		if (i % 2 == 0)
			a0.push_back(a[i]);
		else
			a1.push_back(a[i]);
	}
	vector<long double> y0 = recursiveFFT(a0);
	vector<long double> y1 = recursiveFFT(a1);
	vector<long double> y;

	for (int k = 0; k <= (n/2-1); ++k)
	{
		y[k] = y0[k] + ww * y1[k];
		y[k+(n/2)] = y0[k] - ww*y1[k];
		ww *= ww*n;
	}
}


int main()
{
	cout << "Yo" << endl; // prints Yo
	return 0;
}
