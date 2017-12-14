#ifndef PERSONNELREPORT_H
#define PERSONNELREPORT_H

#include <iostream>
#include "TimeOff.h"

using namespace std;

class PersonnelReport
{
private:
	// class state ...
	TimeOff m_employee;

public:
	// behavior...

	PersonnelReport(); // default ctor
	PersonnelReport(const PersonnelReport & other); // copy ctor
	PersonnelReport(string name, string id, int monthsWorked);

	virtual ~PersonnelReport(); // destructor

	// additional methods
	// ...
	// operator overloads
	friend ostream & operator<<(ostream & os, const PersonnelReport & x);
};

// prototype for the global operator<< function
ostream & operator<<(ostream & os, const PersonnelReport & x);

#endif
