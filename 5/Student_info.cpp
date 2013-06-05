// source file for the Student_info-related functions
#include "Student_info.h"

using std::istream;  using std::vector;

// function to compare for alphabetical sorting
bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

// function to read info for each student
istream& read(istream& is, Student_info& s) {
	
	// read and store the student's name, midterm, and final grades
	is >> s.name >> s.midterm >> s.final;
	
	read_hw(is,s.homework);  // read and store all the student's homework grades
	return is;
}

// function to read in homework grades
istream& read_hw(istream& in, vector<double>& hw) {
	
	if (in) {
		// get rid of previous contents
		hw.clear();
		
		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);
			
		// clear the stream so that input will work for the next student
		in.clear();  // for istream objects .clear() resets any error indications so input can continue
					 // for a vector, it discards its contents leaving an empty vector
	}
	return in;
}

