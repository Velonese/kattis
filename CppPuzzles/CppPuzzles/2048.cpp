#include<stdio.h>
#include<iostream>

using namespace std;

void rotateArray(int direction);
int inputNums[4][4];

int ACCEPTED_2048_main()
{
	int direction;

	for (int i = 0; i < 16; i++)
	{
		cin >> inputNums[i % 4][i / 4];
	}
	
	cin >> direction;
	rotateArray(direction);//rotate into working position.
	int NewRow[4] = { 0 };
	for (int y = 0; y < 4; y++)
	{
		//put all the values of inputNums into a temp row
		for (int x = 0; x < 4; x++)
		{
			NewRow[x] = inputNums[x][y];
		}
		//collapse the row using the rules of the game, same numbers combine. Always collapse to the left:
		int AddedCounter = 0;
		int LastVal = 0;
		for (int x = 0; x < 4; x++)
		{
			if (NewRow[x] != 0)
			{
				if (NewRow[x] == LastVal)
				{
					//add them in order of appearance back into the inputNums
					//because we already added in the value, we need to replace the last value with the new doubled value
					inputNums[AddedCounter - 1][y] = NewRow[x] * 2;
					LastVal = 0;
				}
				else
				{
					//add them in order of appearance back into the inputNums
					inputNums[AddedCounter++][y] = NewRow[x];
					LastVal = NewRow[x];
				}
			}
		}
		//Fill in the rest of the row with zeroes
		for (int x = AddedCounter; x < 4; x++)
		{
			inputNums[x][y] = 0;
		}
	}

	rotateArray(4 - direction);//rotate it back to position.
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			cout << ' ' << inputNums[x][y];
		}
		cout << endl;
	}

	return 0;
}

void rotateArray(int direction)
{
	direction = direction % 4;
	int temp[4][4];
	for (int i = 0; i < direction; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				temp[x][3 - y] = inputNums[y][x];
			}
		}
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				inputNums[x][y] = temp[x][y];
			}
		}
	}
}