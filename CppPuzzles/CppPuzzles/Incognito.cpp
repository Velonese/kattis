#include<stdio.h>
#include<iostream>
#include<string>
#include<map>


using namespace std;

int Accepted_Incognito_main() //https://open.kattis.com/problems/incognito
{
	int testcases, attributes;
	hash<string> strhash;
	cin >> testcases;
	while (testcases--)
	{
		cin >> attributes;
		int result = 1;
		map<size_t, int> matchmap;
		string area;
		while (attributes--)
		{
			cin >> area >> area; //do it twice to skip the one entry
			size_t hashval = strhash(area);

			if (matchmap.find(hashval) == matchmap.end()) {
				matchmap[hashval] = 2; //start at 2 - since they might wear nothing or the item
			}
			else {
				matchmap[hashval]++; //add only 1 each time, since we already considered nothing
			}
		}
		for (auto val : matchmap)
		{
			result *= val.second;
		}
		cout << (result - 1) << endl; //subtract 1 because wearing nothing is not a disguise
	}
	return 0;
}
