//Name:Hsiao-Kang Chang
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-12 Creat this file
//Done on 2024-05-17

#ifndef SENECA_SHOPPINGLIST_H
#define SENECA_SHOPPINGLIST_H
#include <iostream>
namespace seneca{
    const int MAX_NO_OF_RECS = 15;
    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();
}
#endif //SENECA_SHOPPINGLIST_H
