//Name:Hsiao-Kang Chang
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-12 Creat this file
//Done on 2024-05-17

#ifndef SENECA_SHOPPINGREC_H
#define SENECA_SHOPPINGREC_H



namespace seneca{
    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;
    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);


}
#endif //SENECA_SHOPPINGREC_H
