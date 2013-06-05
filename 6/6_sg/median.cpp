// source file for the median function
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <numeric> // for accumulate()
#include "grades.h"
#include "Student_info.h"
using std::domain_error;  using std::sort;  using std::vector;

// compute the mediam of a vector<double>
double median(vector<double> vec) {
	
	typedef vector<double>::size_type vec_sz;
	
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");
		
	sort(vec.begin(),vec.end());
	
	vec_sz mid = size/2;
	
	return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}

// compute the average of a vector<double>
double average(const vector<double>& v) {
	// accumulate sums all items in range given by 2nd & 3rd args
	// the sum is added to an initial value (given as 3rd arg) (0.0 to preserve double nature)
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

// return the median for a vector of Student_info objects
double median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

// return the optimistic median for a vector of Student_info objects
double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

// return median from grades computed with homework averaging
double average_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}
