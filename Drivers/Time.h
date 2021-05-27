#pragma once
#include <iostream>

using namespace std;

struct Time
{
public:
	Time(int s = 0, int m = 0, int h = 0);
	Time(const Time& t);

	int getTimeInSec()const;

	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
	friend Time operator-(const Time& t1, const Time& t2);
	friend bool operator==(const Time& t1, const Time& t2);
	friend bool operator!=(const Time& t1, const Time& t2);
private:
	int sec;
	int min;
	int hours;
};