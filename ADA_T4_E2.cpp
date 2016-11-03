//============================================================================
// Name        : ADA_T4_E2.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int movementMatrix[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char matrix[100][100];
bool visited[100][100];
int r, c;
string pattern;

bool isAValidMovement(int i, int j, char c)
{
	if (i >= 0 && i < r && j >= 0 )
	{
		//cout << "C = " << c << endl;
		//cout << "matrix[i][j] == " << matrix[i][j] << endl;
		//cout << "i = " << i << " j = " << j << endl;
	}
	if (i >= 0 && i < r && j >= 0 && j < c && !visited[i][j] && matrix[i][j] == c)
		return true;
	return false;
}

bool compute(int currentChar, int i, int j)
{
	for (int p = 0; p < 8; ++p)
	{
		//cout << "pattern[currentChar]" << pattern[currentChar] << endl;
		if (isAValidMovement(i+movementMatrix[p][0], j+movementMatrix[p][1], pattern[currentChar]))
		{
			if (currentChar == pattern.size() - 1)
			{
				//cout << "DONE" << endl;
				return true;
			}
			visited[i+movementMatrix[p][0]][j+movementMatrix[p][1]] = true;
			bool result = compute(currentChar + 1, i+movementMatrix[p][0], j+movementMatrix[p][1]);
			visited[i+movementMatrix[p][0]][j+movementMatrix[p][1]] = false;
			if (result)
				return true;
		}
	}
	return false;
}

int main()
{
	memset(visited, false, sizeof(visited));
	cin >> r >> c;
	cin >> pattern;
	//cout << "PATTERN = " << pattern << endl;
	//cout << "PATTERN[0] = " << pattern[0] << endl;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> matrix[i][j];

	bool done = false;

	for (int i = 0; i < r && !done; ++i)
	{
		for (int j = 0; j < c && !done; ++j)
			if (matrix[i][j] == pattern[0])
			{																																																						visited[i][j] = true;
				if(compute(1, i, j))
					done = true;

				visited[i][j] = false;
			}
	}

	if (done)
		cout << "Pattern is in matrix" << endl;
	else
		cout << "Pattern is not in matrix" << endl;

	/*for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			//cout << " " <<  matrix[i][j];
		//cout << endl;
	}*/
	return 0;
}
