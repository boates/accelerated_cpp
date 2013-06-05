// ask for a person's name, and generate a framed greeting
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;

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

    // the number and sum of grades read so far
	int count = 0;
	double sum = 0;    // double is more accurate than float
	
	// a variable in which to read
	double x;    // don't need to initialize w/ a value since we assign it immediately
	// invariant:
	//		we have read 'count' grades so far, and
	//		'sum' is the sum of the first 'count' grades
	while (cin >> x) {    // this condition is satisfied while there is something to read
		++count;          // increments count for each item read
		sum += x;         // sums all grades given
	}
	
	// write the result
	streamsize prec = cout.precision();    // get the current output precision
	cout << "Your final grade is " << setprecision(3)   // set the output precision to 3
	     << 0.2*midterm + 0.4*final + 0.4*sum/count     // write the final grade with precision 3
		 << setprecision(prec) << endl;    // reset precision to its original value
			
    return 0;
}
