#include <iostream>
#include "TimeOff.h"
//#include "NumDays.h"

using namespace std;

// default ctor
TimeOff::TimeOff() :
	m_sickDays(), m_vacationDays()
{

}

// copy ctor
TimeOff::TimeOff(const TimeOff & other) :
	m_sickDays(other.m_sickDays), m_vacationDays(other.m_vacationDays)
{

}

// dtor...
TimeOff::~TimeOff()
{

}

// other methods...
//...
void TimeOff::setMonthsWorked(double months) //sets 8 hours of sick time and 12 hours of vacation time for each month.
{
    m_sickDays.setHours(months*8); //math
    m_vacationDays.setHours(months*12); //math
}

double TimeOff::getSickDays() const
{
    return m_sickDays.getDays();
}

double TimeOff::getVacationDays() const
{
    return m_vacationDays.getDays();
}

ostream & operator<<(ostream & os, const TimeOff & x)
{

	return os;
}
