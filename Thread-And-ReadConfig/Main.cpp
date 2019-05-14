#include "Header.h"


int main(void) {

	ReadConfigFile();	//Read folder path of files wherever you want and extension of files whatever you want.

	vector <string> FilesList = FileNamesInFolder(FolderPath,Extension); //Keep File names

	for (int i = 0; i < FilesList.size(); i++)
	{
		FilesList[i].insert(0, FolderPath); // Add folder path to file name.
	}

	thread thread1(ThreadFunction, FilesList);
	thread1.join();
	cout << "***end***";
	getchar();
}
