#include "Driver.h"

Driver::Driver() 
	: firstName("No label")
	, midName("No label")
	, lastName("No label")
	, startTime()
	, finishTime()
	, startPos("No label")
	, finishPos("No label")
	, km(0.f)
{
}

Driver::Driver(string firstName, string midName, string lastName, Time startTime, Time finishTime, string startPos, string finishPos, float km)
	: firstName(firstName)
	, midName(midName)
	, lastName(lastName)
	, startTime(startTime)
	, finishTime(finishTime)
	, startPos(startPos)
	, finishPos(finishPos)
	, km(km)
{
}

string Driver::getPIP() const
{
	return firstName + " " + midName + " " + lastName;
}

float Driver::getKm() const
{
	return km;
}

Time Driver::getStartTime() const
{
	return startTime;
}

Time Driver::getFinishTime() const
{
	return finishTime;
}

istream& operator>>(istream& in, Driver& t)
{
	in >> t.firstName >> t.midName >> t.lastName >> 
		t.startTime >> t.finishTime >>
		t.startPos >> t.finishPos >> t.km;
	return in;
}

ostream& operator<<(ostream& out, const Driver& t)
{
	out << t.firstName << " " << t.midName << " " << t.lastName << " " <<
		t.startTime << " " << t.finishTime << " " <<
		t.startPos << " " << t.finishPos << " " << t.km << endl;
	return out;


}
