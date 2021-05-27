#include "Time.h"

Time::Time(int s, int m, int h) : sec(s), min(m), hours(h)
{
}

Time::Time(const Time& t) : sec(t.sec), min(t.min), hours(t.hours)
{
}

int Time::getTimeInSec() const
{
	int res = 0;
	if (hours < 0)
		res = (hours + 24) * 60 * 60 + min * 60 + sec;
	else
		res += hours * 60 * 60 + min * 60 + sec;
	return res;
}

istream& operator>>(istream& in, Time& t)
{
	char ch;
	in >> t.hours >> ch >> t.min >> ch >> t.sec;
	return in;
}

ostream& operator<<(ostream& out, const Time& t)
{
	out << t.hours << ":" << t.min << ":" << t.sec;
	return out;
}

Time operator-(const Time& t1, const Time& t2)
{
	int s =0, m = 0, h = 0;

	s = t1.sec - t2.sec;
	if (s < 0)
	{
		s += 60;
		m = -1;
	}
	m += t1.min - t2.min;
	if (m < 0)
	{
		m += 60;
		h = -1;
	}
	h += t1.hours - t2.hours;

	return Time(s, m, h);
}

bool operator==(const Time& t1, const Time& t2)
{
	return t1.sec == t2.sec && t1.min == t2.min && t1.hours == t2.hours;
}

bool operator!=(const Time& t1, const Time& t2)
{
	return t1.sec != t2.sec || t1.min != t2.min || t1.hours != t2.hours;
}
