#ifndef TIMEOFF_H
#define TIMEOFF_H

#include <iostream>
#include "NumDays.h"

using namespace std;

class TimeOff
{
private:
	// class state ...
	NumDays m_sickDays;   //set in the personal report class
	NumDays m_vacationDays; //set in the personal report class call NumDays methods?

public:
	// behavior...

	TimeOff(); // default ctor
	TimeOff(const TimeOff & other); // copy ctor

	virtual ~TimeOff(); // destructor

	// additional methods
	// ...
    void setMonthsWorked(double	months);//	employee should	be	given 8	hours of sick time	and	12 hours of	vacation time for each	month
    double getSickDays() const;// returns the number of sick days the employee has earned
    double getVacationDays() const; //return the number of vacation days the employee has earned.
	
	// operator overloads
	friend ostream & operator<<(ostream & os, const TimeOff & x);
};

// prototype for the global operator<< function
ostream & operator<<(ostream & os, const TimeOff & x);

#endif
