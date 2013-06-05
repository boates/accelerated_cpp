// Chapter 4 grading program
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <algorithm>
#include <vector>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;
using std::sort;
using std::vector;
using std::domain_error;
using std::istream;
using std::max;

struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
}; // note the semicolon; it's required

// function to read in homework grades
istream& read_hw(istream& in, vector<double>& hw)  // last parameter is a *writable* reference, changes to
{												   // hw also change the original variable passed to the fnc
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

// function to read info for each student
istream& read(istream& is, Student_info& s)
{
	// read and store the student's name, midterm, and final grades
	is >> s.name >> s.midterm >> s.final;
	
	read_hw(is,s.homework);  // read and store all the student's homework grades
	return is;
}

// function to compute a sutdent's grade
double grade(double midterm, double final, double homework)
{
	return 0.2*midterm + 0.4*final + 0.4*homework;
}

// function to compute the median of a vector<double>
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");
		
	sort(vec.begin(),vec.end());
	
	vec_sz mid = size/2;
	
	return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}

// function to ask for grades to be computed
double grade(double midterm, double final, const vector<double>& hw)  // the last parameter is defined s.t.
{												     				  // hw is a const reference to 'homework'
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));  // creating two functions w/ the same name is called
											   // overloading, C++ knows which you mean based on the args
}

// function to compute grade for a Student_info object
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

// function to compare for alphabetical sorting
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	
	// read and store all the records and find the length of the longest name
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());  // args of max() must be of *same* type
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
