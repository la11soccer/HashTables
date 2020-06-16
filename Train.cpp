#include "Train.h"
#include <iostream>
Train::Train(string name_in, int number_in)
{
	trainNumber = number_in;
	trainName = name_in;
}
unsigned int Train::hash(int tablesize)
{
	unsigned int value = trainNumber;
	for (int i = 0; i<trainName.size(); i++)
	{
		value += (trainNumber + 11) * value + trainName[i];
	}return value % tablesize;
}

string Train::getName()
{
	return trainName;
}

int Train::getValue()
{
	return trainNumber;
}
ostream & operator << (ostream & out, Train * t)
{
	out << t->trainName << "  " << t->trainNumber;
	return out;
}


