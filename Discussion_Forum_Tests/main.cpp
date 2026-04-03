

//week 3

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void function(int funcNum, int sleepTime){
	cout << "Starting function " << funcNum << "." << endl;
	this_thread::sleep_for(chrono::seconds(sleepTime));
	cout << "Ending function  " << funcNum << "." << endl;

}


int main() {

	cout << "Main Application Starting." << endl;

	thread a(function, 1, 5);
	for (int i = 0; i < 10; i++){
			thread b(function, 2, 4);
			b.detach();
	}

	a.join();


	cout << "Main application completed." << endl;
	return 0;
}

