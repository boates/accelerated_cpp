// test.cpp
#include <string>
#include <vector>
#include <iostream>
#include "urls.h"
using std::cout;  using std::cin;  using std::endl;
using std::vector;  using std::string;

// Run the find_urls function for testing
int main() {

	// read input to string
	string s, str;
	while(getline(cin,s)) {
		str += s;
	}

//	cout << str << endl;

   	// find the urls and print them out
	vector<string> v = find_urls(str);
	for (vector<string>::const_iterator iter=v.begin(); iter != v.end(); ++iter)
		cout << *iter << endl;
	
	return 0;
}

