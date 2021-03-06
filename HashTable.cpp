#include "HashTable.h"

#include <iostream> // DELETE
using std::cout; // DELETE
using std::endl; // DELETE

// private function declaration
int charConvert(char c);
bool isPrime(int); 
int findPrime(int); 
int horner(const string &); 
int hashFunction(const string &); 
void copyTable(const HashTable &); 
int hashFunction2(const string &); 

HashTable::HashTable()
: capacity(101), h2(findPrime(101)), currentNumItems(0)
{
	arr = new string[capacity];
	for (int i=0; i<capacity; i++) {
		arr[i] = "";
	}
}

HashTable::HashTable(int n)
: capacity(findPrime(n*2)), h2(findPrime(n*2)), currentNumItems(0)
{
	arr = new string[capacity];
	for (int i=0; i<capacity; i++) {
		arr[i] = "";
	}
}

HashTable::HashTable(const HashTable & h)
: capacity(h.capacity), h2(h.h2), currentNumItems(h.currentNumItems)
{
	copyTable(h);
}

HashTable::~HashTable()
{
	delete[] arr;
}

HashTable & HashTable::operator=(const HashTable & h)
{
	if (maxSize() > 0) arr->clear(); // empty old array

	if (this != &h) { // don't copy self
		delete[] arr;
		capacity = h.capacity;
		h2 = h.h2;
		currentNumItems = h.currentNumItems;
		copyTable(h);
	}
	return *this;
}

void HashTable::insert(const string & s)
{
	// search hashtable
	int h1 = hashFunction(s);
	while (arr[h1] != "") {
		h1 += h2;
	}
	
	if (!find(s)) arr[h1] = s; // place in array when space is found

	// increase table size if 2/3 full and copy
	if (loadFactor() > 0.67) {
		capacity = findPrime(capacity*2);
		string *temp = arr;
		delete[] arr;
		arr = new string[capacity];
		// copy contents
		for (int i=0; i<capacity; i++) {
			// if (temp[i] != nullptr) 
				arr[i] = temp[i];
			// else arr[i] = "";
		}
		h2 = findPrime(capacity);
	}
}

bool HashTable::find(const string & s) 
{
	int h1 = hashFunction(s);
	while (h1 < capacity) { // stop searching at end of array
		if (arr[h1] == s) return true; // string found
		h1 += h2; // increment
	}

	return false;
}

int HashTable::size() const { return currentNumItems; }
int HashTable::maxSize() const { return capacity; }
float HashTable::loadFactor() const { return currentNumItems/capacity; }

// helpers
bool HashTable::isPrime(int n)
{
	// edge case
	if (n == 0 || n == 1) return false;

	for (int i=2; i<=n/2; i++) {
		// not prime
		if (n % i == 0) return false;
	}
	return true;
}

int HashTable::findPrime(int n)
{
	while (!isPrime(n)) {
		n++;
	}
	return n;
}

// horner's method
// PRE: Only stores lowercase strings
int HashTable::horner(const string & s) 
{ 
    int result = charConvert(s[0]);  // count from first char
  
    // horner's method
    for (int i=1; i<s.length(); i++) 
        result = result*32 + charConvert(s[i]); 
  
    return result; 
} 

void HashTable::copyTable(const HashTable & h)
{
	arr = new string[capacity];
	for (int i=0; i<h.maxSize(); i++) {
		arr[i] = h.arr[i];
	}
}

// double hashing function
int HashTable::hashFunction2(const string & s)
{
	int prime = findPrime(maxSize()/2);

	return prime - (horner(s) % prime);
}

// search key
int HashTable::hashFunction(const string & s)
{
	// define hash1 and hash2
	int h1 = horner(s) % capacity;
	h2 = hashFunction2(s);

	return h1;
}

int charConvert(char c) // set numbers 1 - 26
{
	return c-96;
}

// DELETE LATER
void HashTable::print()
{
	for (int i=0; i<capacity; i++) {
		cout << i+1 << ". " << arr[i] << endl;
	}
}