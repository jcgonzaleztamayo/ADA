//============================================================================
// Name        : ADA_T2_E1.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std;
using namespace std::chrono;

int main()
{
	srand(time(NULL));
	std::map<int, int> elements;

	int n;
	cout << "Por favor entre el tamaño del arreglo a generar:" << endl;
	cin >> n;

	int numOfDiffsElements = ilogb(n);
	cout << numOfDiffsElements << endl;
	vector<int> list;
	list.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		list.push_back(rand() % numOfDiffsElements);
	}


	/*for (int i = 0; i < n; ++i)
		cout << list[i] << " ";
	cout << endl;*/

	auto t0 = high_resolution_clock::now();
	for (int i = 0; i < n; ++i)
		elements[list[i]]++;

	/*std::map<int, int>::iterator it = elements.begin();
	for (; it != elements.end(); ++it)
		cout << "[" << (*it).first << "]=[" << (*it).second << "]" << endl;*/

	int index = 0;
	std::map<int, int>::iterator it = elements.begin();
	for (; it != elements.end(); ++it)
	{
		int t = (*it).second;
		while(t--)
		{
			list[index++] = (*it).first;
		}
	}
	//sort(list.begin(), list.end());

	auto t1 = high_resolution_clock::now();
	cout << endl << "Se ordenó en " << duration_cast<milliseconds>(t1-t0).count() << " milisegundos." << endl << endl;

	/*for (int i = 0; i < n; ++i)
		cout << list[i] << " ";
	cout << endl;*/

	return 0;
}
