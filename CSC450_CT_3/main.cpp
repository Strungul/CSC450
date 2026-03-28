/*
 * main.cpp
 *
 *  Created on: Mar 26, 2026
 *      Author: CWFoo
 */
#include <iostream>
#include <string>

using namespace std;

//wrap allocations in try/catches to prevent bad allocations from corrupting the code
int safeAllocate(int*& ptr){
	try {
			ptr = new int;
		} catch (const bad_alloc& e){
			cout << "Memory allocation failed: " << e.what() << endl;
			return 1;
		}
	return 0;
}

//wrap user entry attempts in try/catches for error handling
int safeAssign(int*& ptr, string sInput) {
	//check for not integer values
	for(char c: sInput){
		if(!isdigit(c)){
			cout << "Invalid input, contains non numeric characters" << endl;
			return 1;
		}
	}

	//convert to int
	try {
			*ptr = stoi(sInput);
		} catch (const invalid_argument& e) {
			cout << "Invalid integer: " << e.what() << endl;
			return 1;
		} catch (const out_of_range& e) {
			cout << "Number is too long: " << e.what() << endl;
			return 1;
		}
	return 0;
}


int main() {

	cout << "Getting Program Ready..." << endl;
	//declare and allocate heap to pointers
	int* input1 = nullptr;
	int* input2 = nullptr;
	int* input3 = nullptr;

	//ensure allocations succeed
	bool fail = true;

	while(fail){
		fail = safeAllocate(input1);
	}

	fail = true;
	while(fail){
		fail = safeAllocate(input2);
	}

	fail = true;
	while(fail){
		fail = safeAllocate(input3);
	}

	int* inputArray[3] = {input1, input2, input3};

	cout << "Program Ready!\n";
	cout << "Welcome to the integer display application. I will ask for three positive integer inputs and will show you\n";
	cout << " what is stored and where that information is stored in memory.\n";
	cout << "\nPlease input those three integers now.\n";

	//intake user values
	for(int i = 0; i < 3; i++){
		string sInput;

		fail = true;
		while(fail){
			cout << "Enter integer " << i + 1 << endl;
			getline(cin, sInput);
			fail = safeAssign(inputArray[i], sInput);
		}

		cout << "The value you entered is " << *inputArray[i] << " and is stored at " << inputArray[i] << endl;
	}

	cout << "The program has concluded.  Thank you for using the application.\n";
	//misleading delete call 'deallocates' or frees memory, does not delete information in pointer, then make sure pointer can't be used.
	//could probably make this into a function as well.  I don't like doing things more than once.
	cout << "Freeing memory..\n";
	delete input1; input1 = nullptr;
	delete input2; input2 = nullptr;
	delete input3; input3 = nullptr;
	cout << "Memory freed.\n";
	cout << "Program Exit";
	return 0;
}




