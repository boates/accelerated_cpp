// ask for a person's name, and generate a framed greeting
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	cout << "Please enter your first name: ";    // ask for their name
	string name;    // define name
	cin >> name;    // read into name
	
	// build the message that we intend to write
	const string greeting = "Hello, " +name+ "!";
	
	// the number of blanks surrounding the greeting
	const int pad = 5;
	
	// total number of rows to write
	const int rows = pad*2 + 3;
	
	// separate the output from the input
	cout << endl;
	
	// loop over number of rows
	for (int r = 0; r != rows; r++) {

        // total number of columns to write
		const string::size_type cols = greeting.size() + pad*2 + 2;
		
		// loop over number of columns
		string::size_type c = 0;
		while (c != cols) {
			
			// check if it is the greeting line
			if (r == pad+1 && c == pad+1) {
				cout << greeting;
				c += greeting.size();
			}
			// if not greeting line perform other checks
			else {
				if (r ==0 || r==rows-1 || c==0 || c==cols-1)
					cout << "*";
				else 
					cout << " ";
				c++;
            }
		}		
		cout << endl;
	}	
    return 0;
}
