//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-26 Creat this file
//Done on

//
#include <iostream>
#include <cstring>
#include "Bill.h"

using namespace std;
namespace seneca {
    //private
    //Adds all the taxes of the items using a loop and returns the sum.
    double Bill::totalTax()const{
        double ret = 0.0;
        int i;
        for ( i = 0; i < m_noOfItems; ++i) {
            ret += m_items[i].tax();
        }
        return ret;
    }
    //Adds all the prices of the items using a loop and returns the sum;
    double Bill::totalPrice()const{
        double ret = 0.0;
        int i;
        for ( i = 0; i < m_noOfItems; ++i) {
            ret += m_items[i].price();
        }
        return ret;
    }

    //print title
    void Bill::Title()const{
        cout << "+--------------------------------------+\n";

        /*Prints the title in the following format:
        //if valid
       /* "| "
        m_title; left-justified in 36 spaces
        " |"
        Newline*/

       //invalid
        /*"| Invalid Bill                         |"<NEWLINE>*/



        //both will print
       /* "+----------------------+---------+-----+"<NEWLIN>
        "| Item Name            | Price   + Tax |"<NEWLIN>
        "+----------------------+---------+-----+"<NEWLIN>*/


    }


    void Bill::footer()const{
        //Prints: "+----------------------+---------+-----+"<NEWLINE>}

        //bill valid
       /* "|                Total Tax: "
        totalTax(); right justified in 10 spaces with two digits after the decimal point
        " |"
        Newline
        "|              Total Price: "
        totalPrice(); right justified in 10 spaces with two digits after the decimal point
        " |"
        Newline
        "|          Total After Tax: "
        totalTax()+totalPrice(); right justified in 10 spaces with two digits after the decimal point
        " |"
        Newline*/



       //invalid
        /*"| Invalid Bill                         |"<NEWLINE>*/



        //both
        /*"+--------------------------------------+"<NEWLINE>*/
    }




    //Sets the Bill object to an empty state by setting m_title to an Empty Cstring and m_items to nullptr
    void Bill::setEmpty(){
        m_title[0] = '\0';
        m_items = nullptr;
    }

    //Returns true if m_title is not empty and m_items is not null and all the Items in the m_items array are valid.
    bool Bill::isValid()const{
        bool ret = true;
        //      hint: First check and make sure m_title and m_items are valid. Then loop through all the Items in the m_items array and make sure they are all valid.
        if (m_title[0] != '\0' && m_items != nullptr){
            int i;
            for(i = 0;i< m_noOfItems;i++){
                if(!m_items[i].isValid()){
                    ret = false;
                }
            }
            ret = true;
        }
        return ret;
    }



    //public:
    /*If any of the arguments are invalid, it will set the Bill to an empty state (ie. title is null or noOfItems is zero or less)

    Otherwise, if the incoming arguments are valid:

    init() function will first set the m_noOfItems member variable to the incoming corresponding argument and sets m_itemsAdded to zero.
    Next, it will copy the Cstring pointed by the title argument into m_title attribute up to 36 characters
            Then it will dynamically allocate an array of Items pointed by m_items member variable. The length of this array will be m_noOfItems.
    Make sure all the dynamically allocated Items are set to empty*/
    void Bill::init(const char* title, int noOfItems){}



   /* If the number of added Items (m_itemsAdded) is less than the length of the m_items array, this function will set the next available subject to the incoming argument values. Then it will add one to the m_itemsAdded and return true;

    Otherwise, this function will do nothing, returning false;*/
    bool Bill::add(const char* item_name, double price, bool taxed){
        bool ret = true;
        return ret;
    }


    //This function will first print the title(), then it will loop through the m_items elements, printing every one of them, and finally prints the footer(). This function can not modify the Bill.
    void Bill::display()const{}

    //Deallocates the m_items arrays and sets the pointers to null.
    void Bill::deallocate(){}

}