#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>

using namespace std;

class NumDays
{
private:
	// class state ...
	double m_hours;
	double m_days;

public:
	// behavior...

	NumDays(); // default ctor
	NumDays(const NumDays & other); // copy ctor
	NumDays(int hours);

	virtual ~NumDays(); // destructor

	// additional methods
	double getHours() const;
	double getDays() const;
	void setHours(double h);//sets hours
	void setDays(double d);// sets days
	void calculateDays(); //Does this setDays(m_hours/8.0);

	// operator overloads
	//friend ostream & operator<<(ostream & os, const NumDays & x);
	friend NumDays operator+( NumDays& a,  NumDays& b);
	friend NumDays operator-( NumDays& a,  NumDays& b); // difference
	NumDays & operator++(); // ++r
	NumDays operator++(int i) ; // r++
	NumDays & operator--(); // ++r
	NumDays operator--(int i); // r++	
};

#endif
