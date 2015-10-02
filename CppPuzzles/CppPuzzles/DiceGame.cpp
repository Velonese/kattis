#include<stdio.h>
#include<iostream>

using namespace std;

int ACCEPTED_DiceGame_main()
{
	float counter = 0;
	float E = 0;
	float G = 0;
	for (int i = 0; i < 8; i++)
	{
		cin >> counter;
		if (i > 3)
		{
			E += counter;
		}
		else
		{
			G += counter;
		}		
	}
	cout << ((E > G) ? "Emma" : (G > E) ? "Gunnar" : "Tie");
	return 0;
}