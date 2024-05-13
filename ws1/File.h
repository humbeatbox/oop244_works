//
// Created by Gary Chang on 2024-05-12.
//

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
