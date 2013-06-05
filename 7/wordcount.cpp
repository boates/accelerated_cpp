// map.cpp
#include <map>
#include <iostream>
using std::cout;  using std::cin;  using std::endl;
using std::string; using std::map;

int main() {

	string s;

	// maps are like dictionaries in python
	map<string, int> counters;
	
	// read the input, keeping track of each word and how often we see it
	while (cin >> s)
		++counters[s];
		
	// write the words and associated counts
	for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}
	return 0;
}