#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <mutex>

using namespace std;

mutex myMutex;

void ThreadFunc(string FileName) {
	
	string line;
	ifstream inFile(FileName);
	while (getline(inFile, line)) {
		myMutex.lock();                   //just one thread uses
		stringstream ss(line);
		cout << line << endl;
		myMutex.unlock();
	}
}

int main(void) {

	string FileName0 = "data_file_0.txt";
	string FileName1 = "data_file_1.txt";
	string FileName2 = "data_file_2.txt";
	
	thread t0([=] {ThreadFunc(FileName0); });
	thread t1([=] {ThreadFunc(FileName1); });
	thread t2([=] {ThreadFunc(FileName2); });

	getchar();
}
