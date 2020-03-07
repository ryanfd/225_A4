#pragma once

#include<string>

using std::string;

class HashTable 
{
public:
	// constructors, destructors, operator
	HashTable();
	HashTable(int);
	HashTable(const HashTable &);
	~HashTable();
	HashTable& operator=(const HashTable &);

	// mutators
	void insert(const string &);

	// accessors
	bool find(const string &) const;
	int size() const;
	int maxSize() const;
	int loadFactor() const;

	// DELETE LATER
	void print();

private:
	string* arr;
	int capacity;
	int h2;
	int currentNumItems;

	// helpers
	bool isPrimte(int); // check if number is prime
	int findPrime(int); // find closest prime equal to or greater than

};