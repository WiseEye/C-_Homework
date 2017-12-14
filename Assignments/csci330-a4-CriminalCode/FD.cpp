#include <iostream> 
#include <iomanip> 
#include <vector> 
#include "utilities/FileReader.h"
#include "utilities/helper.h"
#include "FD.h"

using namespace std;

int main() {
  cout << fixed << setprecision(2);
  vector < Record > origData; // This is the main vector of structs that will be references by other vectors
  populate(origData); // Populates the origData vector
}

//Parses data from a text file, creates a struct for each line, and pushes 
//that struct to origData vector
void populate(vector < Record > & origData) {
  FileReader f("FinancialData.txt");
  string tempA[7];

  while (f.next()) {
    string line = f.readString();
    splitA(line, ',', tempA, 7);
    Record fd;
    fd.typeOfSale = (tempA[0]);
    fd.country = (tempA[1]);
    fd.product = (tempA[2]);
    fd.numberSold = (tempA[3]);
    fd.price = (tempA[4]);
    fd.month = (tempA[5]);
    fd.year = (tempA[6]);
    origData.push_back(fd);
  }

  createVectors(origData); //
}

//populates origData vector with structs, creates vectors of pointers based on
//diffrent conditions, prints out that data
void createVectors(vector < Record > & origData) {
  //Vectors for various conditions
  vector < Record * > justCanada;
  vector < Record * > moreThanhundred;
  vector < Record * > inDecember;
  vector < Record * > combination;

  //create canada vector
  for (int i(0); i < origData.size(); i++) {
    if (origData[i].country == "Canada") {
      Record * pData = & origData[i];
      justCanada.push_back(pData);
    }
  }

  //vector of products that cost more than one hundred dollars

  for (int i(0); i < origData.size(); i++) {
    if (atof(origData[i].price.c_str()) > 100) // anytime you use atof use c_str()
    {
      Record * pData = & origData[i];
      moreThanhundred.push_back(pData);
    }
  }
  //Vector of sales in December
  for (int i(0); i < origData.size(); i++) {

    if (origData[i].month == "December") // anytime you use atof use c_str()
    {
      Record * pData = & origData[i];
      inDecember.push_back(pData);
    }
  }
  //Vector that meets multiple conditions
  for (int i(0); i < origData.size(); i++) {
    if (origData[i].country == "Canada" && atof(origData[i].price.c_str()) > 100 && origData[i].month == "December") // anytime you use atof use c_str()
    {
      Record * pData = & origData[i];
      combination.push_back(pData);
    }
  }
  //Prints totals for diffrent vectors
  cout << "Totals:" << endl;
  cout << "Number of Sales: " << origData.size() << endl;
  cout << "Number of Sales in Canada: " << justCanada.size() << endl;
  cout << "Number of Sales for Products Costing > $100: " << moreThanhundred.size() << endl;
  cout << "Number of Sales in December: " << inDecember.size() << endl;
  cout << "" << endl;
  cout << "Sales meeting all three criteria (Canada, unit price>$100, December):" << endl;
  //calls printRecord to print requierd contence of the struct
  for (int i(0); i < combination.size(); i++) {
    printRecord(combination[i]);
  }

}

//Dereferences pointer and prints out the requierd contence of struct that is refrenced  
void printRecord(Record * r) {
  cout << "Country: " << ( * r).country << ", Product: " << ( * r).product << ", Units Sold: " << ( * r).numberSold << ", Price: " << ( * r).price << ", Month: " << ( * r).month << endl;

}