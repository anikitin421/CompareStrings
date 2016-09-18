/* The program reads and compares whole lines from the file
 * If the search string should be searched everywhere in the file,
 * then it'd be better to change the funktion CompareStrings too.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// Compare Function
bool CompareStrings (string& s1, string& s2 ) {
	printf("    Compare \"%s\" and \"%s\"", s1.c_str(), s2.c_str());

//	for (auto & c: s2) c = toupper(c);
	transform ( s2.begin(), s2.end(), s2.begin(), ::toupper );

	if (s1 == s2)
		printf(" - equal.\n", s1.c_str(), s2.c_str());
	else
		printf(" - not equal.\n", s1.c_str(), s2.c_str());
	return (s1 == s2);
};

// Main Function
int main() {

	string searchString = "Dummy string";
	string line;
	int lineNumber = 0;
	int lineNumbers = 0;
	int matchesCounter = 0;
	const char * fileName = "test.txt";

	// open the file
	ifstream file (fileName);
	if ( !file.is_open() ) {
		printf("Unable to open file \"%s\" to read.\n", fileName);
		return 0;
	}
	printf("\nFile \"%s\" has been opened.\n\n", fileName);

	// prepare the search string
	transform ( searchString.begin(), searchString.end(), searchString.begin(), ::toupper );

	// get the number of lines in the file
	while ( getline (file, line) ) {
		lineNumbers++;
	}

	// read file
	file.clear();
	file.seekg( 0, ios::beg );
	string sa[ lineNumbers ];
	while ( getline (file, sa[ lineNumber++ ]) ) {
//		printf("Read %d line from \"%s\": \"%s\".\n", lineNumber, fileName, sa[ lineNumber - 1 ].c_str());
	}
	file.close();

	// look for the search string
	for ( line : sa ) {
		if ( CompareStrings ( searchString, line ) ) matchesCounter++;
	}

	printf("\nString \"%s\" was found in the file \"%s\" %d times.\n", searchString.c_str(), fileName, matchesCounter);
	return 0;
}
