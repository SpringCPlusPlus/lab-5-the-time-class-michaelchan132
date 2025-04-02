#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    int totalhours = hours + other.hours;
    int totalminutes = minutes + other.minutes;
    if (totalminutes >= 60){
        totalhours += totalminutes / 60;
        totalminutes %= 60;
    }
    return Time(totalhours, totalminutes);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{   
    hours += other.hours;
    minutes += other.minutes;
    if(minutes >= 60){
        hours += minutes / 60;
        minutes = minutes % 60;
    }
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    int thisTotal = hours * 60 + minutes;
    int otherTotal = other.hours * 60 + other.minutes;
    return thisTotal < otherTotal;
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    int thisTotal = hours * 60 + minutes;
    int otherTotal = other.hours * 60 + other.minutes;
    return thisTotal > otherTotal;
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    int thisTotal = hours * 60 + minutes;
    int otherTotal = other.hours * 60 + other.minutes;
    return thisTotal == otherTotal;
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << tm.hours << ":" << (tm.minutes < 10 ? "0" : "") << tm.minutes;
    return os;
}
