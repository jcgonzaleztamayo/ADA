//============================================================================
// Name        : ADA_T4_E3.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

size_t *computePrefixFunction(const string &P)
{
	size_t m = P.length() - 1;
	size_t *pi = new size_t[m + 1];
	pi[1] = 0;
	size_t k = 0;
	for (size_t q = 2; q <= m; ++q)
	{
		while (k > 0 and (P[k + 1] != P[q]))
			k = pi[k];
		if (P[k + 1] == P[q])
			++k;
		pi[q] = k;
		cout << "pi[q] = " << pi[q] << endl;
	}
	return pi;
}

size_t KMPMatcher(const string &_T, const string &_P)
{
	string T = " " + _T;
	string P = " " + _P;
	size_t n = T.length() - 1;
	size_t m = P.length() - 1;
	size_t *pi = computePrefixFunction(P);
	size_t q = 0;							// number of characters matched

	for (size_t i = 1; i <= n; ++i)			// scan the text from left to right
	{
		while (q > 0 and (P[q + 1] != T[i]))
			q = pi[q];						// next character does not match
		if (P[q + 1] == T[i])
			++q;							// next character matches
		if (q == m)							// is all of P matched?
		{
			delete [] pi;
			return i - m;
		}
	}

	delete [] pi;
	return 0;
}

int main()
{
	string T = "bacbababaababacacbab", P = "ca";

	size_t matchingPosition = KMPMatcher(T, P);
	if (matchingPosition)
		cout << "The pattern is in text from position " << matchingPosition + 1 << endl;
	else
		cout << "The pattern is not present in the given text" << endl;
	return 0;
}
