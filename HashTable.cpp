#include "HashTable.h"

#include <iostream> // DELETE
using std::cout; // DELETE
using std::endl; // DELETE

HashTable::HashTable()
: capacity(101), h2(), currentNumItems(0)
{
	for (int i=0; i<capacity; i++) {
		arr[i] = "";
	}
}

HashTable::HashTable(int n)
: capacity(findPrime(2*n)), h2(), currentNumItems(0)
{
	for (int i=0; i<capacity; i++) {
		arr[i] = "";
	}
}

int HashTable::size() const { return capacity; }

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

// DELETE LATER
void HashTable::print()
{
	for (int i=0; i<capacity; i++) {
		cout << i+1 << ". " << arr[i] << endl;
	}
}