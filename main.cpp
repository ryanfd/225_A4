#include "HashTable.cpp"

#include <iostream>

using std::cout;	
using std::endl; 

void initTest();
void testInsert();

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
	HashTable h(10);
	h.insert("cat");
	h.insert("cat");
	h.insert("dog");
	h.insert("cactus");
	h.insert("apple");
	h.insert("apple");

	for (int i=0; i<h.maxSize(); i++) {
		h.insert("a" + i);
	}
	h.print();
}