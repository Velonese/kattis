#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ACCEPTED_SHOPAHOLIC_main()
{
	int items, val;
	long long savings = 0; //with 200,000 items at 200,000 price each, that is 13 billion in savings - too high for an int.
	vector<int> prices;
	cin >> items;
	while (items--)
	{
		cin >> val;
		prices.push_back(val);
	}
	sort(prices.rbegin(), prices.rend()); //rbegin and rend for descending value order
	int counter = 2; //start with the 3rd item, and skip 3 items at a time, adding up the savings.
	while (counter < prices.size())
	{
		savings += prices[counter];
		counter += 3;
	}
	cout << savings << endl;
	return 0;
}