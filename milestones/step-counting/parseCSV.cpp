/**
*
* This program will quickly read a CSV file into the correct data types.
* Testied and working in Win10 and OSX. 
* To compile on OSX use: g++ -std=c++0x parseCSV.cpp -lpthread
*/


//required so will compile in M$FT VS. Must be listed before
//the inclusion of "csv.h"
#define _CRT_SECURE_NO_WARNINGS

//from https://github.com/ben-strasser/fast-cpp-csv-parser
#include "csv.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//create a string with the full/absolute file path for the data to be read.
	string fileName = "14_steps.csv";

	//create the reader object to parse a file with 3 columns
	io::CSVReader<3> in(fileName);

	//tell the class what are the names of the three columns
	in.read_header(io::ignore_extra_column, "x", "y", "z");

	//create variables to hold the data points for each row
	int x; int y; int z;

	//read through the file and do whatever you like with the data
	bool available = true;
	while (available)
	{
		available = in.read_row(x, y, z);
		cout << "x: " << x << " y: " << y << " z: " << z << endl;
	}

	return 0;
}