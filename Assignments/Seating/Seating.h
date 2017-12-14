#ifndef SEATING_H
#define SEATING_H

const int ROWS = 15;
const int COLS = 30;

void getPrices(double p[]);

void initSeating(char s[][COLS]);

void run(double p[], char s[][COLS]);

void printMenue();

void processUserInput(double p[], char s[][COLS]);
    
void ViewSeating(char s[][COLS]);
    
void ViewPrices(double p[]);
    
void BuyTickets(double p[], char s[][COLS]);
    
void NumberRemaining(char s[][COLS]);
    
void TotalSales(double p[], char s[][COLS]);
    
void Quit();

#endif
