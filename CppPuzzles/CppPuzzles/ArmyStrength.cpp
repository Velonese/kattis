#include<stdio.h>
#include<iostream>
#include <string>

using namespace std;

int ACCEPTED_army_easy_main()
{
	int battles, mFighters, gFighters;
	cin >> battles;
	while (battles-- > 0) //don't care about the current number, so this replaces for(...) loop
	{
		int  mStrength = 0, gStrength = 0, tempStrength = 0;
		cin >> gFighters >> mFighters;
		while (gFighters-- > 0)//countdown again
		{
			cin >> tempStrength;
			if (tempStrength > gStrength)
			{
				gStrength = tempStrength;
			}
		}
		while (mFighters-- > 0)//countdown again
		{
			cin >> tempStrength;
			if (tempStrength > mStrength)
			{
				mStrength = tempStrength;
			}
		}
		if (mStrength > gStrength)
		{
			cout << "MechaGodzilla\n";
		}
		else
		{
			cout << "Godzilla\n";
		}
	}
	return 0;
}