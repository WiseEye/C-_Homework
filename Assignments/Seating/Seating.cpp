#include <iostream>
#include <iomanip>
#include "../../utilities/UserInput.h"
#include "../../utilities/FileReader.h"
#include "Seating.h"
#include <string>
#include <ctype.h>


int main()
 {
   try
   {
   char seating[ROWS][COLS];
   double prices[ROWS];
   cout << fixed << setprecision(2);
   getPrices(prices);
   initSeating(seating);
   run(prices, seating);
   }
   catch (const char * msg)
   {
   cout << msg << endl;
   }
  }
  


// populates the prices array with the prices in the
// prices file ...
     void getPrices(double p[])
     {
        UserInput in;
        int i(0); // come back 
        string s = in.readString("Please enter the name of your file: ");
         
        FileReader f(s);
        
        while (f.next())
        {
            
            double num = f.readDouble();
            p[i] = num;
            i++;
        }
     }
     
     
     // initializes the seating array with empty seats...
     void initSeating(char s[][COLS])
     {
       for (int r(0); r < ROWS; r++)
        {
          for (int c(0); c < COLS; c++)
           {
            s[r][c] = '*';
           }
        }
     }
     
     
    // ------------------------------------------------
    //  Kicks of the program
    // ------------------------------------------------
    
     void run(double p[], char s[][COLS])
     {
         printMenue();
         processUserInput(p,s);
     }

    
    void printMenue()
    {
        cout << "------------------" << endl;
        cout << "Menu" << endl;
        cout << "------------------" << endl;
        cout << "S: View Seating Chart" << endl;
        cout << "P: View Prices Chart" << endl;
        cout << "B: Buy Tickets" << endl;
        cout << "R: Number of Remaining Seats" << endl;
        cout << "T: Total Sales" << endl;
        cout << "Q: Quit" << endl;
    }
    
    void processUserInput(double p[], char s[][COLS])
    {
      while(true)
      {
        UserInput in;
        string str = in.readString("Please enter ");
        
        if(str == "s" || str == "S")
            ViewSeating(s);
            
        else if(str == "p" || str == "P")
            ViewPrices(p);
        
        else if(str == "b" || str == "B")
            BuyTickets(p,s);
        
        else if(str == "r" || str == "R")
            NumberRemaining(s);
        
        else if(str == "t" || str == "T")
            TotalSales(p,s);
        
        else if(str == "q" || str == "Q")
            break;
        
        else
            std::cout << "Please Enter a Valid Input \n " << std::endl;;
        
      }
    }
    
    void ViewSeating(char s[][COLS])
    {
      for (int r(0); r < ROWS; r++)
        {
         for (int c(0); c < COLS; c++)
            {
              cout << s[r][c] << " ";
            }
              cout << endl;
        }
    }
    
    void ViewPrices(double p[])
    {
      for (int c(0); c < ROWS; c++)
        {
          cout << "Price For Row " << c+1 << ": " << p[c] << " \n";
        }
          cout << endl;
    }
    
    void BuyTickets(double p[], char s[][COLS])
    {
        
       while(true)
        {
          int tempRow(0);
          int numberOfTickets(0);
          int startSeat(0);
          UserInput in;
          string SeatString(""); //This will keep track of the * or # which represent eaither a taken or untaken seat. 
          tempRow = in.readInt("What Row Would You Like To Buy?");
          
          if(tempRow > ROWS) // Here we make sure that row actually exists
          {
              cout << "Invalid Row" << endl;
              continue;
          }
          
          numberOfTickets = in.readInt("How many seats do you want to buy?");
          startSeat = in.readInt("What is the first seat you want to buy?"); //Remeber to subtract 1 so it works with the arrays and we sont get an off by one error
       
        //Check if those seats are takem. Maybe make this a seperate methose by its self
        for (int r(0); r < numberOfTickets; r++)/////////////////////
        {
            SeatString = s[tempRow -1][(startSeat -1) + r];
            if(SeatString == "#")
                {
                  std::cout << "It looks like one of these seats are taken" << std::endl;
                  continue;
                }
        }
        
       // cout << SeatString << endl;  DEBUG
        
         // if these seats are not taken then we will fill them by replacing the * with a #
            for (int r(0); r < numberOfTickets; r++)
            {
               s[tempRow -1][(startSeat -1) + r] = '#';
            }
           /// ViewSeating(s); DEBUG
         
         double RowPrice = p[tempRow - 1];
         double Price = RowPrice * numberOfTickets;
         
         cout << "Total: " << Price << endl;
         break;
        
        }
    }
    
    void NumberRemaining(char s[][COLS])
    {
        int count(0);
        for (int r(0); r < ROWS; r++)
        {
         for (int c(0); c < COLS; c++)
            {
              if(s[r][c] == '*')
              {
                count++;
              }
            }
        }
        
        std::cout << "There are " << count << " seats left" << std::endl;
    }
    
    void TotalSales(double p[], char s[][COLS])
    {
        int count(0);
        double TotalPrice(0.0);
        double RowPrice(0.0);
        double Price(0.0);
        
      for (int r(0); r < ROWS; r++)
        {
           for (int c(0); c < COLS; c++)
            {
              RowPrice = p[r]; // r is for row
              if(s[r][c] == '#')
              {
                count++;
                
              }
            }
            Price = RowPrice * count;
            TotalPrice = TotalPrice + Price;
            break;
            //cout << "Total Sales Are: " << TotalPrice << endl;
        }
        cout << "Total Sales Are: " << TotalPrice << endl;
    }
    
