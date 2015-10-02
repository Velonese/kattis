#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int ACCEPTED_AlphabetSoup_main()
{
	string input;
	double length = 0,
		white = 0,
		lower = 0,
		upper = 0,
		symbol = 0;

	getline(cin, input);
	length = input.length();
	
	cout << setprecision(15);

	for (string::iterator a = input.begin(); a != input.end(); a++)
	{
		if (*a == '_')
		{
			white++;
		}
		else if (islower(*a))
		{
			lower++;
		}
		else if (isupper(*a))
		{
			upper++;
		}
		else
		{
			symbol++;
		}
	}

	cout << white / (white + upper + symbol + lower) << endl;
	cout << lower / (white + upper + symbol + lower) << endl;
	cout << upper / (white + upper + symbol + lower) << endl;
	cout << symbol / (white + upper + symbol + lower) << endl;

	return 0;
}