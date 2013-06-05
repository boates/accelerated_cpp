// utils.cpp
#include <stdexcept>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using std::string;  using std::vector;  using std::max;

// vector concatenation function (i.e. vcat(['a','b'], ['c','d','e']) = ['a','b','c','d','e'])
vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
	vector<string> ret = top;  // originally copy the whole top list
	for (vector<string>::const_iterator iter=bottom.begin(); iter != bottom.end(); ++iter) {
		ret.push_back(*iter);
	}

	// using an insert command performs the equivalent task
//	ret.insert(ret.end(),bottom.begin(),bottom.end());
	
	// using copy can also do the same (back_inserter is an iterator adaptor)
//	copy(bottom.begin(), bottom.end(), back_inserter(ret));

	return ret;
}

// true if arg is whitespace, false otherwise
bool space(char c) {
	return isspace(c);
}

// false if the arg is whitespace, true otherwise
bool not_space(char c) {
	return !isspace(c);
}

// a new version of split function using standard algorithms
vector<string> split(const string& str) {
	typedef string::const_iterator iter;
	vector<string> ret;
	
	iter i = str.being();
	while (i != str.end()) {

		// ignore leading blanks
		i = find_if(i, str.end(), !space);

		// find the end of the next word
		iter j = find_if(i, str.end(), space);
		
		// copy the characters in [i,j)
		if (i != str.end()) {
			ret.push_back(string(i,j));
		}
		i = j;
	}
	return ret;
}

// Determine if a given string is a palindrome
bool is_palindrome(const string& s) {
	return equal(s.begin(), s.end(), s.rbegin());
}















