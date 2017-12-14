#include <vector>
#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include "utilities/FileReader.h"
#include "utilities/helper.h"
#include "utilities/UserInput.h"
#include "NumDays.h"
#include "PersonnelReport.h"



int main()
{
 try
 {
 UserInput i;
 FileReader in(i.readString("Enter employee file: "));
 while (in.next())
 {
 vector<string> tokens = split(in.readString(), ',');
 PersonnelReport rpt(tokens[0], tokens[1], atof(tokens[2].c_str()));
 cout << rpt << endl;
 }
 }
 catch (const char * msg)
 {
 cout << msg << endl;
 }
}