// Chapter 6 grading program
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
using std::cin;  			using std::cout;	using std::endl;
using std::string;  		using std::vector;	using std::streamsize;
using std::setprecision;	using std::sort;	using std::domain_error;
using std::max;

int main()
{
	vector<Student_info> did, didnt;
	Student_info student;
	string::size_type maxlen = 0;	// for length of the longest name
	
	// read all student records and separate based on whether all homeowrk was done
	while (read(cin, student)) {
//		did_all_hw(student) ? did.push_back(student) : didnt.push_back(student);
		if (did_all_hw(student)) {
		did.push_back(student);
    	} else {
			didnt.push_pack(student);
		}
	}
	
	// Check that both groups contain data
	if (did.empty()) {
		cout << "No student did all of the homework!" << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Every student did all of the homework!" << endl;
		return 1
	}
	
	// do the analysis
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0;
}
