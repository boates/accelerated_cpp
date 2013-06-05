// analysis.cpp
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
using std::cin;  			using std::cout;	using std::endl;
using std::string;  		using std::vector;

void write_analysis(ostream& out, const string& name,
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
				   ", mediam(didnt) = " << analysis(didnt) << endl;
					
}