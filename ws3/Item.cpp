//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-26 Creat this file
//Done on

//

#include "Item.h"
#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
namespace seneca {

    //private
        //for set the m_itemName
        void Item::setName(const char* name){}//for set the m_itemName
    //public:
        //set the Item to Empty State
        //m_itemName to
        //etting the m_itemName to a blank string (first character set to null)
        void Item::setEmpty(){}

/*    Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName method and sets the m_price and m_taxed attributes to the corresponding arguments.
    If price is less than 0 or name is null, then the Item is set to a recognizable invalid empty state (safe empty state).*/
        void Item::set(const char* name, double price, bool taxed){}

/*    Prints an item in the following format.
    If the Item is valid:*/
        void Item::display()const{}

        //Returns true if the Item is not set to the empty state (As done in setEmpty function) .
        //This function can not modify its owner.
        bool Item::isValid()const{
            bool ret = true;


            //If the Item is valid:
/*            "| "
            m_itemName; left-justified in 20 spaces, padded with '.' (dots)
            " | "
            m_price; right-justified in 7 spaces with two digits after the decimal point
            " | "
            if m_taxed is true prints "Yes" otherwise prints "No "
                                                             " |"
            Newline*/

            return ret;
        }

        //Returns the m_price attribute;
        double Item::price()const{
            double ret = 0.0;
            return ret;
        }
        //Returns the product of m_price and 0.13(define a constant double value for this tax rate). Or it returns 0.0 if the m_taxed is false.
        double Item::tax()const{
            double ret = 0.0;
            return ret;
        }

}