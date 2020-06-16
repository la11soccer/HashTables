#include <iostream>
#include "Train.h"
#include "HashTable.h"
using namespace std;

int main()
{
	//create 3 new trains
	Train* train1 = new Train("4-4-2", 343);
	Train* train2 = new Train("2-9-0", 344);
	Train* train3 = new Train("4-0-4", 345);
	Train* train4 = new Train("2-8-0", 1);
	Train* train5 = new Train("2-8-0", 2);
	Train* train6 = new Train("2-8-0", 3);
	Train* train7 = new Train("12-0-0", 42);
	Train* train8 = new Train("12-0-12", 84);
	Train* train9 = new Train("2-2", 2);
	Train* train10 = new Train("4-4", 4);
	Train* train11 = new Train("2-8-0", 99);
	//create a hashtable
	HashTable hashTableOne = HashTable();
	cout << hashTableOne;
	hashTableOne.Insert(train1);
	hashTableOne.Insert(train2);
	hashTableOne.Insert(train3);


	cout << "original print\n" << hashTableOne;

	hashTableOne.Insert(train1);
	hashTableOne.Insert(train2);
	hashTableOne.Insert(train3);

	cout << "print after adding same three again\n" << hashTableOne;

	hashTableOne.Insert(train3);
	hashTableOne.Insert(train4);
	hashTableOne.Insert(train5);
	hashTableOne.Insert(train6);
	hashTableOne.Insert(train7);
	hashTableOne.Insert(train8);
	hashTableOne.Insert(train9);
	hashTableOne.Insert(train10);

	cout << "Printing out with now 10 trains\n" << hashTableOne;
	/*
	hashTableOne.remove(train1);
	hashTableOne.remove(train2);
	hashTableOne.remove(train3);

	hashTableOne.Insert(train11);
	hashTableOne.remove(train11);*/

	cout << "final PRint: \n" << hashTableOne;


}