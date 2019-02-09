#include "Header.h"


int main(void) {

	ReadConfigFile();	//Read folder path of files wherever you want and extension of files whatever you want.

	vector <string> FilesList = FileNamesInFolder(FolderPath,Extension); //Keep File names

	for (int i = 0; i < FilesList.size(); i++)
	{
		FilesList[i].insert(0, FolderPath); // Add folder path to file name.
	}

	for (int i = 0; i < FilesList.size(); i++)
	{
		thread t0(ThreadFunc, FilesList[i]);  // Call line of files
		t0.join();
	}


	// This Part will Change
	/*if (counterForReadLines == FilesList.size())
	{
		for (int i = 0; i < counterForStringVectorFirstLineIndex; i++)
		{
			cout << StringVectorFirstLine[i] << endl;
		}
		for (int i = 0; i < counterForStringVectorSecondLineIndex; i++)
		{
			cout << StringVectorSecondLine[i] << endl;
		}
		for (int i = 0; i < counterForStringVectorThirdLineIndex; i++)
		{
			cout << StringVectorThirdLine[i] << endl;
		}
		for (int i = 0; i < counterForStringVectorForthLineIndex; i++)
		{
			cout << StringVectorForthLine[i] << endl;
		}
	}*/

	getchar();
}