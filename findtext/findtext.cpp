#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool stringIsFound(ifstream & fileToSearch, const string & searchString)
{
	bool isFound = false;
	string line;
	for (int lineIndex = 1; getline(fileToSearch, line); ++lineIndex)
	{
		if (line.find(searchString) != string::npos)
		{
			isFound = true;
			cout << "\"" << searchString << "\" was found in the " << lineIndex << " line" << endl;
		}
	}
	return isFound;
}

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl
			 << "Usage: findtext.exe <input file> <search string>" << endl;
		return 1;
	}

	ifstream fileToSearch(argv[1]);

	if (!fileToSearch.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading" << endl;
		return 1;
	}

	string searchString = argv[2];
	if (searchString.empty())
	{
		cout << "Search string is empty" << endl;
		return 1;
	}

	if (!stringIsFound(fileToSearch, searchString))
	{
		cout << searchString << " was not found in " << argv[1] << endl;
		return 1;
	}

	return 0;
}
