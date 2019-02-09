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

//vector <string> StringVector;
//vector <string> StringVectorFirstLine;
//vector <string> StringVectorSecondLine;
//vector <string> StringVectorThirdLine;
//vector <string> StringVectorForthLine;

//vector <double> DoubleVector;
//
//int counterForDoubleVectorIndex = -1;   // Negative Number. Because of index starts with 0.
//int counterForStringVectorIndex = -1;   // Negative Number. Because of index starts with 0.
//int counterForReadLines;
//int counterForStringVectorFirstLineIndex;
//int counterForStringVectorSecondLineIndex;
//int counterForStringVectorThirdLineIndex;
//int counterForStringVectorForthLineIndex;


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



void ThreadFunc(string FileName)
{
	string line;
	ifstream inFile(FileName);
	while (getline(inFile, line)) {
		stringstream ss(line);
		cout << line << endl;
		/*StringVector.push_back(line);
		counterForStringVectorIndex++;
		string token;
		vector <string> TempStringVector;
		while (getline(ss, token, '.'))
		{
			TempStringVector.push_back(token);
			if (TempStringVector.size() % 2 == 1 )
			{
				DoubleVector.push_back(stod(TempStringVector[0]));
				counterForDoubleVectorIndex++;
			}
		}
		if (DoubleVector[counterForDoubleVectorIndex] == 1)
		{
			StringVectorFirstLine.push_back(StringVector[counterForStringVectorIndex]);
			counterForStringVectorFirstLineIndex++;
		}
		else if (DoubleVector[counterForDoubleVectorIndex] == 2)
		{
			StringVectorSecondLine.push_back(StringVector[counterForStringVectorIndex]);
			counterForStringVectorSecondLineIndex++;
		}
		else if (DoubleVector[counterForDoubleVectorIndex] == 3)
		{
			StringVectorThirdLine.push_back(StringVector[counterForStringVectorIndex]);
			counterForStringVectorThirdLineIndex++;
		}
		else if (DoubleVector[counterForDoubleVectorIndex] == 4)
		{
			StringVectorForthLine.push_back(StringVector[counterForStringVectorIndex]);
			counterForStringVectorForthLineIndex++;
		}*/

	}
	//counterForReadLines++;
}


#endif //!HEADER_H
