//============================================================================
// Name        : CompareStrings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

// Source strings are converted to uppercase to be compared insensitive
//
// Parameters s1 and s2 are copies of attributes str1 and str2
// to protect the attributes from changing
// return 1=equal
bool CompareStrings(string s1, string s2) {

	for (auto & c: s1) c = toupper(c);
	for (auto & c: s2) c = toupper(c);
	return (s1 == s2);
};

int main() {
 // Strings to compare
	string str1 = "Abc";
	string str2 = "aBC";
	cout << CompareStrings(str1, str2) << endl;
	return 0;
}
