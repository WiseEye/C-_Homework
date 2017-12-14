#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <algorithm> 
#include "../utilities/FileReader.h"
#include "../utilities/FileWriter.h"
#include "PeskyTourist.h"

using namespace std;

int main()
{
     //vector < FileReader > readers;
    vector<FileReader> photos;
    
      string filename = "images/Pesky1.ppm";
      FileReader fr(filename);
      //readers.push_back(fr);
      std::cout << "lol" << std::endl;
    
    //try
   // {
        
        //FileReader p("images/Pesky1.ppm");
        photos.push_back(fr);
   // }
    
    //catch (const char * error)
   // {
      //  cout << error << endl;
   // }
     
}

