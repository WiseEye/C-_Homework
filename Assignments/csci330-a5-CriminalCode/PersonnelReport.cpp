#include <iostream>
#include "PersonnelReport.h"

using namespace std;

// default ctor
PersonnelReport::PersonnelReport() :
	m_employee()
{

}

// copy ctor
PersonnelReport::PersonnelReport(const PersonnelReport & other) :
	m_employee()
{

}
//Constructor that is passed the name id and number of months worked. This is passed from the main file
PersonnelReport::PersonnelReport(string name, string id, int monthsWorked) :
	m_employee()
{
    //setMonthsWorked is a function in TimeOff
    m_employee.setMonthsWorked(monthsWorked);
    // We have to print out their name and id information before we print out 
    // their vactaiondays because they will be out off scope of the << operator
    cout << name  << " (" << id <<") " ; 
}

// dtor...
PersonnelReport::~PersonnelReport()
{

}

// other methods...
//...

ostream & operator<<(ostream & os, const PersonnelReport & x)
{
    os<< "Vacation Days " << x.m_employee.getVacationDays() <<" Sick Days " << x.m_employee.getSickDays() << endl;
    
	return os;
}
