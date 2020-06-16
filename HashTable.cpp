#include <iostream>
#include "Train.h"
#include <list>
#include <iterator>
#include <vector>
#include "HashTable.h"
using namespace std;

HashTable::HashTable()
{
	numberOfEntries = 0;
	sizeOfTable = 2;
	//hasharray holds lists of train*
	HashArray = new list<Train*>[sizeOfTable];
}

bool HashTable::Insert(Train* trainIn)
{
	//boolean to hold whether the train was found in the list
	bool inList = false;
	//boolean to keep track of if the table was rehashed
	bool reHashed = false;
	//variable to keep track of whether or not the variable was inserted
	bool inserted = false;
	//list* temp = new list(string > ;
	//hash the function which will return the index of where the train needs to go 
	hashIndex = trainIn->hash(sizeOfTable);
	//check and see if the train is in the table already
	//create an iterator to loop through the list
	
	//if(HashArray[hashIndex].contains(trainIn))

	for (list<Train *>::iterator it = HashArray[hashIndex].begin(); it != HashArray[hashIndex].end(); it++)
	{
		//it is giving us the train in each linked list 
		//if the name and value are the same as a train in the current train set the variable inList to tr
		Train* tempTrain = *it;
		if (tempTrain->getName() == trainIn->getName() && tempTrain->getValue() == trainIn->getValue())
		{
			inList = true;
			inserted = false;
			break;
		}
		else
		{
			inList = false;
		}
	}
	//if the train was not in the list, add it to the front of the list 
	if (inList == false)
	{
		HashArray[hashIndex].push_front(trainIn);
		//increase entries by 1
		numberOfEntries++;
		inserted = true;
		//cout << numberOfEntries << endl;
	}

	if (numberOfEntries > sizeOfTable * 2)
	{
		rehash();
		reHashed = true;
	}
	else
	{
		reHashed = false;
	}
	return inserted;
}

int HashTable::getSize() const
{
	return sizeOfTable;
}

ostream & operator << (ostream & out, HashTable tempTable) 
{

	//out << "Size of array: " << tempTable.getSize() << "\n";
	//for loop to go through the size of the array held in the variable sizeOfTable
	for (int i = 0; i< tempTable.getSize() ; i++)
	{
		out << i << ": ";
		list<Train*>* TrainListArray = tempTable.getArray();
		if (TrainListArray[i].size() > 0)
		{
				
					for (list<Train*>::iterator it = TrainListArray[i].begin(); it != TrainListArray[i].end(); it++)
					{
						Train* temp = *it;
						out << temp<<"    ";
					}
					out << "\n" ;		
		}
		else
		{
			out << "\n";
		}
	}
		//out << t->trainName << "  " << t->trainNumber;
	return out;
}

list<Train*>* HashTable::getArray() const
{
	return HashArray;
}

bool HashTable::find(Train* trainIn)
{
	toRemove = 0;
	int count = 0;
	bool found = false;
	//get the index of the train passed in 
	hashIndex = trainIn->hash(sizeOfTable);
	for (list<Train*>::iterator it = HashArray[hashIndex].begin(); it != HashArray[hashIndex].end(); it++)
	{
		//it is giving us the train in each linked list 
		//if the name and value are the same as a train in the current train set the variable inList to tr
		Train* tempTrain = *it;
		//increment count everyloop
		count++;
		if (tempTrain->getName() == trainIn->getName() && tempTrain->getValue() == trainIn->getValue())
		{
			toRemove = count;
			found = true;
			break;
		}
		else
		{
			found = false;
		}
	}
	return found;
}

void HashTable::remove(Train* trainIn)
{	
	//call the find method on the given train
	//returns true if the train was found 
	bool wasFound = find(trainIn);

	if (wasFound == true)
	{
		hashIndex = trainIn->hash(sizeOfTable);
		//list<Train*> tempList = HashArray[hashIndex];
		list<Train*> ::iterator it = HashArray[hashIndex].begin();
		
		cout <<*it;
		advance(it, toRemove);
		Train* temp = *it;
		cout << temp;
		HashArray[hashIndex].erase(it);
	}
	/* 
	{
		hashIndex = trainIn->hash(sizeOfTable);
		for (list<Train*>::iterator it = HashArray[hashIndex].begin(); it != HashArray[hashIndex].end(); it++)
		{
			//it is giving us the train in each linked list 
			//if the name and value are the same as a train in the current train set the variable inList to tr
			Train* tempTrain = *it;

			if (tempTrain->getName() == trainIn->getName() && tempTrain->getValue() == trainIn->getValue())
			{
				
			}
			
		}
	}*/
}

void HashTable::rehash()
{
	vector<Train*> vectorOfTrains;

	//for loop to loop through the hasharray
	for (int i = 0; i < HashArray->size(); i++)
	{
		//for loop to loop through the list 
		for (list<Train*>::iterator it = HashArray[i].begin(); it != HashArray[i].end(); it++)
		{
			Train* temp = *it;
			//add the train to the vector
			vectorOfTrains.push_back(temp);
		}
	}
	//increase size of table by 2
	sizeOfTable = sizeOfTable * 2;

	numberOfEntries = 0;

	HashArray = new list<Train*>[sizeOfTable];
	for (int i = 0; i < vectorOfTrains.size(); i++)
	{
		Insert(vectorOfTrains.at(i));
	}


}
