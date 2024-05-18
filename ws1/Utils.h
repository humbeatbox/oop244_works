//Name:Hsiao-Kang Chang
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-12 Creat this file
//Done on 2024-05-17

#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca{

    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}
#endif //SENECA_UTILS_H
