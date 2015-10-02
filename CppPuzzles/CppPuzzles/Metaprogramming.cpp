#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int ACCEPTED_METAPROGRAMMING_main()
{
	string line, function, word, key1, key2;
	int val;
	map<string, int> variablestorage;

	while (getline(cin, line))
	{
		istringstream linestream(line);
		linestream >> function;
		if (function == "eval")
		{
			//collect first variable until operator
			linestream >> key1 >> word;
			while (word != "=" && word != ">" && word != "<")
			{
				key1 += " " + word;
				linestream >> word;
			}
			//collect operator
			function = word;
			//collect second variable
			linestream >> key2;
			while (linestream >> word)
			{
				key2 += " " + word;
			}

			auto found1 = variablestorage.find(key1);
			auto found2 = variablestorage.find(key2);

			string result;

			if (found1 == variablestorage.end() || found2 == variablestorage.end())
			{
				result = "undefined";
			}
			else
			{
				if (
					(function == "=" && (found1->second == found2->second)) ||
					(function == "<" && (found1->second < found2->second)) ||
					(function == ">" && (found1->second > found2->second))
					)
				{
					result = "true";
				}
				else
				{
					result = "false";
				}
			}
			cout << result << endl;
		}
		else
		{
			linestream >> val >> key1;
			while (linestream >> word)
			{
				key1 += " " + word;
			}
			variablestorage[key1] = val;
		}
	}

	return 0;
}
