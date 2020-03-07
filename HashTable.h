#pragma once

using std::string;

class HashTable 
{
public:
	// constructors, destructors, operator
	HashTable();
	HashTable(int n);
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

private:
	string* arr;
	int size;
	int h2;
	int currentNumItems;
};