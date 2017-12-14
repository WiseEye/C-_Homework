#include <iostream>
#include "NumDays.h"

using namespace std;

// default ctor
NumDays::NumDays() :
	m_hours(0.0), m_days(0.0) // this is how we set the member variables
{
calculateDays();
}

// copy ctor
NumDays::NumDays(const NumDays & other) :
	m_hours(other.m_hours), m_days(other.m_days)
{

}

NumDays::NumDays(int hours) : m_hours(hours)
{
    calculateDays(); //This isnt nessisary
}

// dtor...
NumDays::~NumDays()
{

}

// other methods...
//...

double NumDays::getHours() const
{
    return m_hours;
}

double NumDays::getDays() const
{
    return m_days;
}

void NumDays::setHours(double h) //calculate hours
{
    m_hours = h;
    setDays(m_hours/8.0);
}

void NumDays::setDays(double d)
{
    m_days = d;
}

void NumDays::calculateDays()
{
    setDays(m_hours/8.0);
}

NumDays operator+( NumDays& a,  NumDays& b)
{
    NumDays ret;
    double temp = a.getHours() + b.getHours();
    ret.setHours(temp);
    ret.setDays(temp/8.0);
    return ret;
    
}

NumDays operator-( NumDays& a,  NumDays& b)
{
    NumDays ret;
    double temp = a.getHours() - b.getHours();
    ret.setHours(temp); 
    ret.setDays(temp/8.0);
    return ret;
}

NumDays & NumDays::operator++()
{
	m_hours++;
	setDays(m_hours/8.0);
	return *this;
}

NumDays NumDays::operator++(int i)
{
  NumDays ret(m_hours);
  m_hours = m_hours+1;
  setDays(m_hours/8.0);
 
return ret;
}

NumDays & NumDays::operator--()
{
	m_hours--;
	setDays(m_hours/8.0);
	return *this;
}

NumDays NumDays::operator--(int i)
{
    
  NumDays ret(m_hours);
  m_hours = m_hours-1;
  setDays(m_hours/8.0);
  return ret;
}
