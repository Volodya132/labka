#pragma once
#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

struct Driver
{
public:
	Driver();
	Driver(string firstName, string midName, string lastName, Time startTime, Time finishTime, string startPos, string finishPos, float km);

	string getPIP()const;
	float getKm()const;
	Time getStartTime()const;
	Time getFinishTime()const;

	friend istream& operator>>(istream& in, Driver& t);
	friend ostream& operator<<(ostream& out, const Driver& t);
private:
	string firstName;
	string midName;
	string lastName;
	Time startTime;
	Time finishTime;
	string startPos;
	string finishPos;
	float km;
};