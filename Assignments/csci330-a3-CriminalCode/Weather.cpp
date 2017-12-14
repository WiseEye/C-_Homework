#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <algorithm> 
#include "utilities/FileReader.h"
#include "utilities/helper.h"
#include "Weather.h"

using namespace std;

int main() {
    vector < HighLow > temps;
    populate(temps);
    chart(temps);
  }
  // populate a vector with the temps in file
void populate(vector < HighLow > & temps) {
  FileReader f("temps.txt");
  string tempA[2]; //array to hold high and low temperatures after split

  while (f.next()) {//spits all temperaturs in file
    string line = f.readString();
    splitA(line, ',', tempA, 2);
    HighLow t;
    t.high = stoi(tempA[0]);
    t.low = stoi(tempA[1]);
    temps.push_back(t);
  }
}

// prints the ASCII chart to the console
void chart(const vector < HighLow > & temps) {
    vector < string > wChart;
    wChart = makeCharts(temps); //Line 44

    cout << "<=40         :" << wChart[0] << endl;
    cout << ">40 and <=50 :" << wChart[1] << endl;
    cout << ">50 and <=60 :" << wChart[2] << endl;
    cout << ">60 and <=70 :" << wChart[3] << endl;
    cout << ">70          :" << wChart[4] << endl;
  }
  //returns a vector containing the ASCII chart 
vector < string > makeCharts(const vector < HighLow > & temps) {
    
  vector < string > wChart = {
    "",
    "",
    "",
    "",
    ""
  };
  //puts in "-" for low temperatures
  for (int i(0); i < temps.size(); i++) {
    int lowtemp = temps[i].low;

    if (lowtemp <= 40)
      wChart[0] = wChart[0] + '-';

    if (lowtemp > 40 && lowtemp <= 50)
      wChart[1] = wChart[1] + '-';

    if (lowtemp > 50 && lowtemp <= 60)
      wChart[2] = wChart[2] + '-';

    if (lowtemp > 60 && lowtemp <= 70)
      wChart[3] = wChart[3] + '-';

    if (lowtemp > 70)
      wChart[4] = wChart[4] + '-';
  }

  //puts in "+" for high temperatures
  for (int k(0); k < temps.size(); k++) {
    int hightemp = temps[k].high;

    if (hightemp <= 40)
      wChart[0] = wChart[0] + '+';

    if (hightemp > 40 && hightemp <= 50)
      wChart[1] = wChart[1] + '+';

    if (hightemp > 50 && hightemp <= 60)
      wChart[2] = wChart[2] + '+';

    if (hightemp > 60 && hightemp <= 70)
      wChart[3] = wChart[3] + '+';

    if (hightemp > 70)
      wChart[4] = wChart[4] + '+';
  }

  return wChart; //returns completed chart vector
}