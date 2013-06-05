// words.cpp
#include <stdexcept>
#include <string>
#include <vector>
#include <cctype>
using std::string;  using std::vector;  using std::max;

// function that splits a string sentence into a vector<string> of words
vector<string> split(const string& s) {
	
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;
	
	// invariant: we have processed characters [original value of i, i)
	while (i != s.size()) {

		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;
		
		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j) is a space
		while (j != s.size() && !isspace(s[j]))
			++j;
			
		// if we found some nonwhitespace characters
		if (i != j) {
			// copy from s starting at i and taking j-1 characters
			ret.push_back(s.substr(i,j-i));
			i = j;  // push index i to the end of the word we just parsed
		}
	}
	return ret;
}

// function that determines the length of the longest string in a vector<string>
string::size_type width_old(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i=0; i != v.size(); ++i)
		maxlen = max(maxlen, v[i].size());
	return maxlen;
}

// function that determines the length of the longest string in a vector<string> using iter
string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;
	for (vector<string>::const_iterator iter=v.begin(); iter != v.end(); ++iter)
		maxlen = max(maxlen, (*iter).size());
	return maxlen;
}

// create a frame around a vector<string> to print to screen
vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen+4,'*');
	
	// write the top border
	ret.push_back(border);
	
	// write the interior row, bordered by an asterisk and a space
	for (vector<string>::const_iterator iter=v.begin(); iter != v.end(); ++iter) {
		ret.push_back("* "+(*iter)+string(maxlen - iter->size(),' ') + " *");
	}
	
	// write the bottom border
	ret.push_back(border);
	
	return ret;
}

// vector concatenation function (i.e. vcat(['a','b'], ['c','d','e']) = ['a','b','c','d','e'])
vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
	vector<string> ret = top;  // originally copy the whole top list
	for (vector<string>::const_iterator iter=bottom.begin(); iter != bottom.end(); ++iter) {
		ret.push_back(*iter);
	}

	// using an insert command performs the equivalent task
//	ret.insert(ret.end(),bottom.begin(),bottom.end());

	return ret;
}

// horizontal concatenation of two "pictures"
vector<string> hcat(const vector<string>& left, const vector<string>& right) {
	vector<string> ret;
	
	// add 1 to leave a space between pictures
	string::size_type width_p_1 = width(left) + 1;
	
	// indices to look at elements from left and right, respectively
	vector<string>::size_type i=0, j=0;
	
	// continue until we've seen all rows from both pictures
	while (i != left.size() || j != right.size()) {
		// construct new string to hold characters from both pictures
		string s;
		
		// copy a row from left (if there is one)
		if (i != left.size())
			s = left[i++];	// puts left[i] in s and then increments i
		
		// pad to full width
		s += string(width_p_1 - s.size(), ' ');
		
		// copy a row from the right (if there is one)
		if (j != right.size())
			s += right[j++];	// puts right[j] in s and then increments j
		
		// add s to the picture we are creating
		ret.push_back(s);
	}
	return ret;
}














