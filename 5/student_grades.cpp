// Chapter 4 grading program
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
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;	// for length of the longest name
	
	// read and store all the records
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());  // find length of longest name
		students.push_back(record);
	}
	
	// alphabetize the records
	sort(students.begin(), students.end(), compare);
	
	for (vector<Student_info>::size_type i=0; i != students.size(); ++i) {

		// write the name, padded on the right to maxlen+1 characters
		cout << students[i].name << string(maxlen+1 - students[i].name.size(),' ');
		
		// compute and write the grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}	
		cout << endl;
	}
    return 0;
}
