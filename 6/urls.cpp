// urls.cpp
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using std::string;  using std::vector;  using std::max;
using std::cout;  using std::cin;  using std::endl;

// determines if a character is allowed as part of a URL
bool not_url_char(char c) {
	// characters, in addition to alphanumerics, that can appear in a URL
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	
	// see whether c can appear in a URL and return the negative
	// find returns the iterator if it finds the 3rd arg, otherwise returns 2nd arg
	// *return if c is not an alphanumeric] or is not in url_ch*
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

// function to find the iterator for the beginning of a URL
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
	static const string sep = "://";
	typedef string::const_iterator iter;
	
	// i marks where the separator was found
	iter i = b;
	
	while (( i = search(i, e, sep.begin(), sep.end())) != e) {
		// make sure the separator isn't at the beginning or end of the line
		if (i != b && i + sep.size() != e) {
			// beg marks the beginning of the protocol-name
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))  // while beg isn't b and is an alphabetic character
				--beg;  // iterate beg down, eventually to the beginning of the protocol-name
			
			// is there at least one appropriate character before and after the separator?
			if (beg != i && !not_url_char(i[sep.size()])) {
				return beg;
			}
		}
		// the separator we found wasn't part of a URL; advance i past this separator
		i += sep.size();
	}
	return e;
}

// function to find the iterator for the end of a URL
string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
	return find_if(b, e, not_url_char);
}

// function to detect URLs in a body of text
vector<string> find_urls(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();
	
	// look through the entire input
	while (b != e) {
		// look for one or more letters followed by ://
		b = url_beg(b,e);
		
		// if we found it
		if (b != e) {
			// get the rest of the URL
			iter after = url_end(b,e);
			
			// remember the URL
			ret.push_back(string(b,after));
//			cout << string(b,after) << " b=" << *b << " after=" << *after << endl;

			// advance b and check for more URLs on this line
			b = after;
		}
	}
	return ret;
}
















