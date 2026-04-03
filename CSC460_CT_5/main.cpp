/*
 * main.cpp
 *
 *  Created on: Apr 3, 2026
 *      Author: CWFoo
 */

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <iterator>

using namespace std;

// method takes in two file paths, reverses contents of first path and outputs new file with the reversed contents to second path
int writeReverse(filesystem::path iFile, filesystem::path oFile ){
	cout << "Starting file reverse" << endl;
	string fileData;
	string bufferData;
	ifstream inFile(iFile, ios::binary);
	string iFileString = iFile.string();
	string oFileString = oFile.string();

	if(!inFile.is_open()){
			cout << "Attempt to open file " << iFileString << " failed.  Please check if the file is open and that this program has permissions to the file." << endl;
			return 1;
		}

	fileData.assign((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());

	//got rid of this version, as it did not ingest newline characters properly
	/*
	while (getline(inFile, bufferData)) {
		cout << "Reading file lines...\n";
		fileData += bufferData;
	}
*/
	//inFile.clear();
	inFile.close();
	if (inFile.bad()){
		cout << "Error occurred while closing the " << iFileString << " file." << endl;
		return 1;
	}

	cout << "File ingestion Complete." << endl;

	//using a standarzided approach because the class seems more focused on file management than it does string manipulation logic like previous classes
	cout << "Reversing contents..." << endl;
	reverse(fileData.begin(), fileData.end());
	cout << "Contents reversed." << endl;

	cout << "Writing reversed string to new file..." << endl;
	ofstream outFile(oFile, ios::binary);
	outFile << fileData;
	if (outFile.fail()){
		cout << "Error occurred while writing to " << oFileString << endl;
		return 1;
	}

	outFile.close();
	if (outFile.fail()){
		cout << "Error occurred while saving the file to " << oFileString << endl;
		return 1;
	}

	cout << "File successfully reversed and written to " << oFileString << endl;
	return 0;
}

int main(){
	// communicate with the user
	cout << "System initializing...\n";

	//validate existence of expected file located in C:\Users\CWFoo\eclipse-workspace_cpp\CSC460_CT_5
	//could be enhanced by allowing user to enter file path themselves.
	cout << "Validating file..." << endl;
	filesystem:: path filePath = R"(C:\Users\CWFoo\eclipse-workspace_cpp\CSC460_CT_5)";
	filesystem:: path fileName = "CSC450_CT5_mod5.txt";
	filesystem:: path iFile = filePath / fileName;

	cout << filePath.string() << endl;
	if (filesystem::exists(iFile)){
		cout << "File existence verified." << endl;
	} else {
		cout << "File not found.  Exiting Program." << endl;
		return 1;
	}

	cout << "Welcome.  Please enter some string of values.  This will be appended to the configured file.\n";
	cout << "I will then reverse the order of all of the characters in the file and produce a new file for you in the same location.\n";
	//retrieve user input
	string input;
	do {
		cout << "Please enter your string now." << endl;
		getline(cin, input);
	} while (input.empty());

	//write input to file
	cout << "Appending your text to the configured file..." << endl;

	ofstream outfile(iFile, ios::app);
	if(!outfile.is_open()){
		cout << "Attempt to open file failed.  Please check if the file is open and that this program has permissions to the file." << endl;
		return 1;
	}

	outfile << input;
	if (outfile.fail()){
		cout << "Error occurred while writing to the file." << endl;
		return 1;
	}

	outfile.close();
	if (outfile.fail()){
		cout << "Error occurred while saving the file." << endl;
		return 1;
	}

	//reverse file data and save in new file

	filesystem:: path fileName2 = "CSC450-mod5-reverse.txt";
	filesystem:: path oFile = filePath / fileName2;

	return writeReverse(iFile, oFile);



	return 0;
}


