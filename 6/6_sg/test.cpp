// test.cpp
#include <string>
#include <vector>
#include <iostream>
#include "utils.h"
using std::cout;  using std::cin;  using std::endl;
using std::vector;  using std::string;

///*
// Print a sentence word by word using the split function
int main() {

	string s;

	// read and split each line of input
	while(getline(cin,s)) {
 
		vector<string> v = split(s);
		
		// frame the split sentence
		vector<string> f = frame(v);
		
		// do a horizontal concatenation of v and f
		vector<string> h = hcat(v,f);
		
		// now frame a frame of the hcat
		vector<string> r = hcat(frame(frame(h)),frame(hcat(v,frame(frame(v)))));

  		// write the frame
		for (vector<string>::const_iterator iter=r.begin(); iter != r.end(); ++iter)
			cout << *iter << endl;
	}
	return 0;
}
//*/

/*
// Print a sentence word by word from input directly
int main() {
	string s;
	while (cin >> s)
		cout << s << endl;
	return 0;
}
*/