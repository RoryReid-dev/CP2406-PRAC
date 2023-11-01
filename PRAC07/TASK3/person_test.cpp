#include "Person.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	Person person{"Craig", "David"};
	person.output(cout);

	ostringstream stringstream;
	person.output(stringstream);

	ofstream outFile{"./person.txt", ios_base::app};
	person.output(outFile);
}
