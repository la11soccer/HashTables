#pragma once
#include <iostream>
#include "Train.h"
#include <list>
#include <iterator>
#include <vector>
using namespace std;
class HashTable
{
public:
	//constructor 
	HashTable();
	bool Insert(Train* trainIn);
	list<Train*>* getArray() const;
	int getSize() const;
	bool find(Train* trainIn);
	void remove(Train* trainIn);
	void rehash();
	
	
private:
	int numberOfEntries=0;
	int sizeOfTable=0;
	//vector<vector<Train*> > HaTable;
	list<Train*>* HashArray;
	int hashIndex;
	int toRemove=0;
};

ostream& operator << (ostream& out, HashTable tempTable);