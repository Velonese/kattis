#include<stdio.h>
#include<iostream>

using namespace std;

int ACCEPTED_Peragrams_main()
{
	int Results[26] = { 0 };//26 possible letters, we will store the counts here.
	char feed;
	int CharCount = 0;
	bool SubtractOne = false;

	while (cin.get(feed) && feed != '\n')
	{
		Results[feed - 97]++; //lowercase 'a' is 97, lowercase 'z' is 26 higher.
		CharCount++;
	}
	for (int i = 0; i < 26; i++)
	{
		if ((Results[i] % 2) == 1)
		{
			SubtractOne = true;
			CharCount -= (Results[i] - 1);
		}
		else
		{
			CharCount -= Results[i];
		}
	}
	if (SubtractOne)
	{
		CharCount--;
	}
	cout << CharCount << endl;
	return 0;
}