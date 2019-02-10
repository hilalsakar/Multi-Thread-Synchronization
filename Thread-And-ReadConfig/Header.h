#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>

#include <Windows.h>
#include <algorithm>

#include <thread>
#include <mutex>
#include <vector>

using namespace std;

string FolderPath;
string Extension;

void ReadConfigFile()
{
	ifstream FileIn("Config.txt");
	if (FileIn.is_open())
	{
		string Line;
		while (getline(FileIn, Line))
		{
			Line.erase(remove_if(Line.begin(), Line.end(), isspace), Line.end());
			auto SplitPos = Line.find(":");
			auto Name = Line.substr(0, SplitPos);
			auto Variable = Line.substr(SplitPos + 1);

			if (strcmp(Name.c_str(), "FolderPath") == 0) // if there is a Folder path, 
			{
				FolderPath = Variable.c_str(); //keep it.
			}
			else if (strcmp(Name.c_str(), "Extension") == 0)  // if there is a File extension, 
			{
				Extension = Variable.c_str(); // keep it.
			}
		}
	}
	else
	{
		cout << "Couldn't open Config.txt file" << endl;
	}
}

vector <string> FileNamesInFolder(string FolderPath, string Extension)  //Using folder path and extension that is from config file,
																		//keep data file names
{
	vector <string> Names;
	string SearchPath(FolderPath);
	SearchPath.append("\\*.");
	SearchPath.append(Extension);

	WIN32_FIND_DATA Data;
	HANDLE hFind = FindFirstFile(SearchPath.c_str(), &Data);      // *.txt files in path of directory 
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			Names.push_back(Data.cFileName);    // Here Names are.
		} while (FindNextFile(hFind, &Data));
		FindClose(hFind);
	}

	return Names;
}

void ThreadFunction(vector <string> FileList)
{
	vector <ifstream> fin(FileList.size());
	string line;
	for (int i = 0; i < fin.size(); i++)
	{
		fin[i].open(FileList[i]);		//Files open.
	}
	
	for (int i = 0; true ; )
	{
		if (fin[i].is_open())
		{
			while (getline(fin[i],line))
			{
				cout << line << endl;
				i++;							// to read one line in each loop.
				if ( i == FileList.size() )
				{
					i = 0;						// to turn back first file for other line.
				}
			}
		}
	}
}


#endif //!HEADER_H
