//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-17 Creat this file
//Done on

#ifndef SENECA_FILE_H
#define SENECA_FILE_H
namespace seneca {
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();
    // TODO: Declare read prototypes

    bool read(char* name);
    bool read(int &intNum);
    bool read(double &dulNum);
}

#endif //SENECA_FILE_H
