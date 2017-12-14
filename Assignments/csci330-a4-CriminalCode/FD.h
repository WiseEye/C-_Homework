#ifndef FD_H
#define FD_H

//#include <vector>

using namespace std;

struct Record
{
	 string typeOfSale;
	 string country;
	 string product;
	 string numberSold;
	 string price;
	 string month;
	 string year;
	 
};
void populate( vector < Record > & origData);
void createVectors( vector < Record > & origData);
void printRecord(Record * r);
#endif

