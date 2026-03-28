

//week 3

#include <iostream>
#include <string>

using namespace std;

int main() {

	int array[3] = {1,2,3};
	int* pointer = array;
	cout << *pointer << endl;; //will print 1
	cout << *(pointer + 1) << endl; // will print 2
	cout << array[2] << endl; //will print 3
	int five = *(pointer + 1) + array[2];
	cout << five; //will print 5


	return 0;
}

