#include "HashTable.cpp"
#include "spellcheck.h"

#include <iostream>
#include <random>

using std::cout;	
using std::endl; 

void initTest();
void testInsert();
vector<string> readFile(string infile);

int main()
{
	// initTest();
	testInsert();
}

void initTest()
{
	HashTable h;
	cout << h.maxSize() << endl;
	HashTable h2(h);
	cout << h2.maxSize() << endl;
	HashTable h3 = h2;
	cout << h3.maxSize() << endl;

	HashTable h4(7);
	cout << h4.maxSize() << endl;
}

void testInsert()
{
	HashTable h(100);
	// h.insert("cat");
	// h.insert("cat");
	// h.insert("dog");
	// h.insert("cactus");
	// h.insert("apple");
	// h.insert("apple");
	// h.insert("cake");
	// h.insert("cattle");
	// h.insert("cactuses");
	// h.insert("cactu");
	// h.insert("cater");

	vector<string> list = readFile("wordList1000.txt");
	for (int i=0; i<80; i++) {
		int index = rand() % list.size();
		h.insert(list[index]);
	}

	h.print();
}