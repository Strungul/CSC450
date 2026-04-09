

/* Tasks
 * Create C++ application - Done
 * Create two threads to act as counters -
 * Thread 1 count up to 20
 * Thread 2 count down to 0
 * Assume customer wants to actually see the counts, print values after counting
 *
 */

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int countPrint(int* counter, int goal, char direction = '+'){
	if (direction != '+' && direction != '-') {
		cerr << "Invalid count direction.\n";
		return 1;
	}


	if(direction == '+') {
		if (*counter >= goal){
			cout << "Counter value " << *counter << " already greater than or equal to goal value."<< endl;
			return 0;
		}
		cout << *counter << "\n";
		while(*counter < goal){
			(*counter)++;
			cout << *counter << "\n";
		}

	}

	if(direction == '-') {
		if (*counter <= goal){
			cout << "Counter value " << *counter << " already less than or equal to goal value."<< endl;
			return 0;
			}
		cout << *counter << "\n";
		while(*counter > goal){
			(*counter)--;
			cout << *counter << "\n";
		}
	}

	return 0;

}

int main() {
	cout << "It's counting time!\n";
	int countVariable = 0;
	try {
		thread a(countPrint, &countVariable, 20, '+');
		a.join();
	} catch (const system_error& e) {
		cerr << "Thread a creation failed: " << e.what() << endl;
		return 1;
	}

	try {
	thread b(countPrint, &countVariable, 0, '-');
	b.join();
	} catch (const system_error& e) {
		cerr << "Thread b creation failed: " << e.what() << endl;
		return 1;
	}


	cout << "Counting time is over!";
	return 0;
}


