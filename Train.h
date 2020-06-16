#pragma once
#ifndef TRAIN_H
#define TRAIN_H
#include <string>
using namespace std;
class Train
{public:
	string trainName;
	int trainNumber;
	Train(string name_in, int number_in);
	unsigned int hash(int tablesize);
	string getName();
	int getValue();
};

ostream & operator << (ostream & out, Train * t);
#endif