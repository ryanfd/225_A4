#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iterator>

#include "HashTable.h"

using std::string;
using std::vector;
using std::ifstream;
using std::runtime_error;
using std::istream_iterator;

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

// one letter difference
vector<string> extraLetter(const HashTable & ht, string word)
{
	vector<string> result;

	// if (!ht.find(word)) {
	// 	// vector<string> wordList = readFile(wordList1000.txt);
	// } else {
	// 	result.push_back(word);
	// }

	return result;
}
