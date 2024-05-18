//Name:Hsiao-Kang Chang
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-12 Creat this file
//Done on 2024-05-17

#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include "ShoppingRec.h"
namespace seneca{

    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif //SENECA_FILE_H
