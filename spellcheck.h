#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

// Opens a file and reads the contents into a vector
// PARAM: infile = name of the file to be opened
// PRE: the file contains words separated by white space
// POST: returns a vector containing the contents of infile
vector<string> readFile(string infile)
{
	ifstream ist(infile.c_str());
	if (ist.fail())
		throw runtime_error(infile + " not found");
	istream_iterator<string> start(ist), end;
	vector<string> result(start, end);

	ist.close();
	return result;
}

vector<string> extraLetter(const HashTable & ht, string word)
{
	vector<string> result;

	return result;
}
