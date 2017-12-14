#ifndef PIC_H
#define PIC_H

const int NumberOfFiles = 9;
void sortColor(FileWriter& fw,int c[]);
void makeHeader(FileWriter& fw);
void populateVector(vector<FileReader> &readers);
void ignoreHeader(FileReader &temp, vector<FileReader> &readers);
void writeFinalFile(int colors[], FileReader &temp, vector<FileReader> &readers, FileWriter& fw);

#endif
