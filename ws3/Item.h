//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-26 Creat this file
//Done on 2024-05-27

//

#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_
namespace seneca {
    class Item {
        char m_itemName[21]{};
        double m_price{};
        bool m_taxed{};
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, double price, bool taxed);
        void display()const;
        bool isValid()const;
        double price()const;
        double tax()const;
    };
}

#endif // !SENECA_SUBJECT_H
