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

int main()
{
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, "+name+"!" << endl;
	
	// ask for and read the midterm and final exam grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;
	
	// ask for the homework grades
	cout << "Please enter all of your homework grades, followed by end-of-file: ";

	vector<double> homework;
	
	// read the homework grades
	read_hw(cin, homework);
	
	// compute and generate the final grade if possible
	try {
		double final_grade = grade(midterm, final, homework);
     	streamsize prec = cout.precision();    // get the current output precision
    	cout << "Your final grade is " << setprecision(3)   // set the output precision to 3
		     << final_grade << setprecision(prec) << endl;  // reset precision to its original value
	} catch (domain_error) {
		cout << endl << "You must enter your grades\n"
             			"Please try again.\n" << endl;
	}

    return 0;
}
