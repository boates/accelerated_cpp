// ask for a person's name, and generate a framed greeting
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;
using std::sort;
using std::vector;

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
	cout << "Please enter all of your homework grades, "
        	"followed by end-of-file: ";

	// a variable in which to read
	double x;    // don't need to initialize w/ a value since we assign it immediately
	vector<double> homework;    // like an array
	while (cin >> x) {    // this condition is satisfied while there is something to read
		homework.push_back(x);  // store all grades in homework vector, push_back is like append
	}
	
	typedef vector<double>::size_type vec_sz;   // alias vec_sz as this type
	vec_sz size = homework.size();              // use the type of vec_sz to intialize size
												// vector.size() is like len(array)
												
	// check that at least one homework grade was given
	if (size == 0) {
		cout << "You must enter your grades. "
       			"Please try again." << endl;
			return 1;
	}
	
	// determine the median
	sort(homework.begin(), homework.end());  // sort(vector) like list.sort()
	
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];
	// check the condition, if true executes between ? and :, if false executes after :
	
	// write the result
	streamsize prec = cout.precision();    // get the current output precision
	cout << "Your final grade is " << setprecision(3)   // set the output precision to 3
	     << 0.2*midterm + 0.4*final + 0.4*median        // write the final grade with precision 3
		 << setprecision(prec) << endl;    // reset precision to its original value
			
    return 0;
}
