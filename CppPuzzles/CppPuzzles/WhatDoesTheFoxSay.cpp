#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int ACCEPTED_What_Does_The_Fox_Say_main()
{	
	int testcases;
	std::cin >> testcases;
	for (int i = 0; i < testcases; i++)
	{
		std::cin.ignore();//handles newline '\n' left in the input buffer after reading one word at a time
		std::vector<std::string> recording;
		std::vector<std::string> knownanimalsounds;
		bool RemoveNextWord = false;
		bool KeepReading = true;
		std::string word;
		std::string recordedline;
		std::getline(std::cin, recordedline);
		std::istringstream stringstream(recordedline);

		while (stringstream >> word)
		{
			recording.push_back(word);
		}

		while (KeepReading) {
			std::cin >> word;
			if (RemoveNextWord)
			{
				knownanimalsounds.push_back(word);
			}
			KeepReading = word != "say?";
			RemoveNextWord = word == "goes";
		}
		bool FirstSoundPrinted = true;//spacing problem
		for (int i = 0; i < recording.size(); i++)
		{
			bool PrintSound = true;
			for (int x = 0; x < knownanimalsounds.size(); x++)
			{
				if (knownanimalsounds[x] == recording[i])
				{
					PrintSound = false;
					x += knownanimalsounds.size();
				}
			}
			if (PrintSound)
			{				
				std::cout << (FirstSoundPrinted ? "" : " ") << recording[i];
				FirstSoundPrinted = false;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}