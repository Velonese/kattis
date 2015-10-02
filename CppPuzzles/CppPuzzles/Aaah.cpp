#include<stdio.h>
#include<iostream>

using namespace std;

int ACCEPTED_aaah_main()
{
	long long val1, val2;
	while (cin >> val1 >> val2)
	{
		cout << ((val1 > val2) ? val1 - val2 : val2 - val1) << endl;
	}

	return 0;
}