/*
 * main.cpp
 *
 *  Created on: Mar 22, 2026
 *      Author: CWFoo
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
	//example from 6.1.3 of sei-cert-cpp-2016.pdf
	//string input; //getting rid of this because it is never used
	string stringOne, stringTwo;

	cout << "Hello!  In this program I will be asking you to enter two inputs three times.  I will join those inputs together to give you a result.  I have not bounded the length of the inputs as the reading material has indicated that the best practice is to \n";
	cout << "use the string library to intake the values.\n";

	for (int i = 0; i < 3; i++) {
		cout << "Please enter your first value.\n";
		//using getline() from structured-programming-with-c-plus-plus.pdf section 5.8 instead of just cin
		getline(cin, stringOne);
		cout << "Please enter your second value.\n";
		getline(cin, stringTwo);

		//check for user just hitting the enter key

		if (stringOne.empty()) {
			cout << "Just skipping the first value is a little boring.  I'll add my dog's name to spice things up.\n";
			stringOne = "Theo is a good Boy.";
		}

		if (stringTwo.empty()){
			cout << "Just skipping the second line is a little boring.  I'll add an activity to make things fun.\n";
			stringTwo = "Do you want to play fetch?";
		}

		cout << "You've entered " << stringOne << " and " << stringTwo << ".\n";
		cout << "Together they make " << stringOne << stringTwo << "!\n";
		cout << endl; // buffer flush
	}

	cout << "Thank you for using the concatenator!";


	return 0;
}







