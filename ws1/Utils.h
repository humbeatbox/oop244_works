//
// Created by Gary Chang on 2024-05-12.
//

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
