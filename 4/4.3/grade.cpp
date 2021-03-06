// source file for the grade functions
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;  using std::vector;

// function to compute a sutdent's grade
double grade(double midterm, double final, double homework) {
	return 0.2*midterm + 0.4*final + 0.4*homework;
}

// function to ask for grades to be computed
double grade(double midterm, double final, const vector<double>& hw) {
	
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));  // creating two functions w/ the same name is called
											   // overloading, C++ knows which you mean based on the args
}

// function to compute grade for a Student_info object
double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}