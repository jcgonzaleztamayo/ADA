//============================================================================
// Name        : ADA_T4_E1.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int main()

{
	int counter['z' + 1];
	bool original['z' + 1];
	int different = 0;
	memset(counter, 0, sizeof(counter));
	memset(original, false, sizeof(original));
	string C, S;
	cin >> S >> C;
	for (size_t i = 0; i < C.size(); ++i)
	{
		if (!counter[(size_t)C[i]])
		{
			++different;
		}
		++counter[(size_t)C[i]];
		original[(size_t)C[i]] = true;
	}

	size_t beginSubStr = 0;
	size_t iMinWin = 0, jMinWin = -1;

	for (size_t i = 0; i < S.size(); ++i)
	{
		if (original[(size_t)S[i]])
		{
			counter[(size_t)S[i]]--;
			if (counter[(size_t)S[i]] == 0)
				different--;
		}

		if (different == 0)
		{
			while ((beginSubStr < i)
					&& ((!original[(size_t)S[beginSubStr]])
							|| (original[(size_t)S[beginSubStr]] && counter[(size_t)S[beginSubStr]] < 0)))
			{
				if (counter[(size_t)S[beginSubStr]] < 0)
					++counter[(size_t)S[beginSubStr]];
				++beginSubStr;
			}

			if (i - beginSubStr < jMinWin - iMinWin)
			{
				iMinWin = beginSubStr;
				jMinWin = i;
			}
		}
	}
	if (jMinWin != (size_t)-1)
		cout << S.substr(iMinWin, jMinWin - iMinWin + 1) << endl;
	else
		cout << "" << endl;

	return 0;
}
