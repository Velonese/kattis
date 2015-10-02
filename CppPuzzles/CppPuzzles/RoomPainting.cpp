#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int ACCEPTED_ROOMPAINTING_main()
{
	int shop = 0, joe = 0;
	double val = 0, wastedpaint = 0;
	vector<double> shopcans;
	cin >> shop >> joe;
	while (shop--)
	{
		cin >> val;
		if (val > 0)
		{
			shopcans.push_back(val);
		}
	}
	sort(shopcans.begin(), shopcans.end());
	while (joe--)
	{
		cin >> val;
		if (val > 0)
		{
			int i = 0;
			while (shopcans[i++] - val < 0);
			wastedpaint += shopcans[i - 1] - val;
		}
	}
	cout.precision(16);//<--- TOOK 2 HOURS TO FIGURE OUT - Without this, it only fails on the last problem with "Wrong Answer"
	//Problem should include the required precision in the question, but instead only loosely implies it by saying joe measures
	//microliters, and values up to 1000. big frustration. Input on the site should include these circumstances instead of leaving
	//students to just guess what went wrong.
	cout << wastedpaint << endl;
	return 0;
}