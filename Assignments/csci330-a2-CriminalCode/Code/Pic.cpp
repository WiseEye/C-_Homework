#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <algorithm> 
#include "../utilities/FileReader.h"
#include "../utilities/FileWriter.h"
#include "Pic.h"
//I love Annie
using namespace std;

int main() {
  FileWriter fw("../images/Output.ppm"); //Create the output file
  makeHeader(fw); //Line 70
  vector < FileReader > readers; //A vector of file readers to read each file 
  //NumberOfFiles is a const that holds the number of files
  populateVector(readers); //Line 56

  FileReader temp = readers[3]; // Create a temp FileReader so we can call next() in a while loop without affecting the Readers in reader vector

  ignoreHeader(temp, readers); //Line 41

  int colors[NumberOfFiles]; // An array to hole the first line of each of the 9 files

  writeFinalFile(colors, temp, readers, fw);

}
// Peforms a while loop that sorts, finds the mean, and writes out the result to our file
void writeFinalFile(int colors[], FileReader & temp, vector < FileReader > & readers, FileWriter & fw) {
  while (temp.next()) {
    for (int i(0); i < NumberOfFiles; i++) {
      colors[i] = readers[i].readInt();
      readers[i].next();
    }

    sortColor(fw, colors); // Line 77
  }

  fw.close(); //Make sure to close the file
}
//Calls next() in order to skip the first 4 lines of the ppm file. The 5th line is were we want to start
void ignoreHeader(FileReader & temp, vector < FileReader > & readers) {
  for (int t(0); t < NumberOfFiles; t++) {
    readers[t].next();
    readers[t].next();
    readers[t].next();
    readers[t].next();
    readers[t].next();
  }
// You must call next() on our temp Reader as well or it will not write out the proper information
  temp.next();
  temp.next();
  temp.next();
  temp.next();
}
//Finds and adds to a Vector of FileReaders NOTE: This may be over complicated. PHRV
void populateVector(vector < FileReader > & readers) {
  try {
    for (int i = 1; i <= NumberOfFiles; i++) {
      string filename = "../images/Pesky";
      filename += to_string(i);
      filename += ".ppm";
      FileReader fr(filename);
      readers.push_back(fr);
    }
  } catch (const char * msg) {
    cout << msg << endl;
  }
}
//Write the first neccisary lines of the ppm file or the "Header"
void makeHeader(FileWriter & fw) {
  fw.writeLine("P3");
  fw.writeLine("#");
  fw.writeLine("495 557");
  fw.writeLine("255");
}
//Calls the sort function on our color array and writes the 5th element which is the medium
void sortColor(FileWriter & fw, int c[]) {
  sort(c, c + NumberOfFiles);
  fw.writeLine(c[(NumberOfFiles-1)/2]); // NumberOfFiles = 9. 5th element --> 9-1 = 8 --> 8/2 =4 
}