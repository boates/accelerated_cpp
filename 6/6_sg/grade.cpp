// source file for the grade functions
#include <stdexcept>
#include <vector>
#include <list>
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

// predicate to determine whether a student failed
bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

// separate passing and failing student records: first try
list<Student_info> extract_fails(vector<Student_info>& students) {
	list<Student_info> pass, fail;
	list<Student_info>::iterator iter = students.begin()  // iterator vs. const_iterator
	while (iter != students.end()) {
		if (fgrade(*iter))
			fail.push_back(*iter);        // same as appending students[i]
			iter = students.erase(iter);  // not const_iterator b/c we change it
		else
			++iter;
	}
	return fail;
}

// function to check if a student has completed all of their homework
bool did_all_hw(const Student_info& s) {
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homeowkr.end());
}

// function to implement a catch and allow for proper overloading
double grade_aux(const Student_info& s) {
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

// return the students grade calculated using an average of the homework grades
double average_grade(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

// median of the nonzero elements of s.homework, or zero if no such elements exist
double optimistic_median(const Student_info& s) {
	vector<double> nonzero;
	
	// remove_copy acts like remove but copies results to indicated destination
	// this will remove all 0 values (4th arg) from a range (1st & 2nd args) and copy
	// the remaining to 3rd arg
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
	
	// Check if there were any nonzero grades at all, if not return 0 as homework grade
	if (nonzero.empty()) {
		return grade(s.midterm, s.final, 0);
	} else {
		return grade(s.midterm, s.final, median(nonzero));
	}
}




















