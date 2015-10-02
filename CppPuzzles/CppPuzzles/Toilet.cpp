#include <iostream>

using namespace std;

int Toilet_Accepted_main()
{
	int sumUp = 0, sumDown = 0, sumPref = 0;
	char preference, initial;

	cin >> initial;

	cin >> preference;

	if (initial == preference)
	{
		if (preference == 'U')
		{
			sumDown++;
		}
		else
		{
			sumUp++;
		}
	}
	else
	{
		if (preference == 'U')
		{
			sumDown+=2;
			sumUp++;
		}
		else
		{
			sumUp+=2;
			sumDown++;
		}
		sumPref++;
	}
	initial = preference;
	while (cin.get(preference) && preference != '\n')
	{
		if (initial != preference)
		{
			sumPref++;
			//we are changing the value;
		}
		if (preference == 'D')
		{
			sumUp+=2;
		}
		else
		{
			sumDown+=2;
		}
		initial = preference;
	}
	cout << sumUp << endl << sumDown << endl << sumPref << endl;
	return 0;
}
