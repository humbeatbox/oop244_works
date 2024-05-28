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
        void Item::setName(const char* name){
        //TODO :should deallocate and it's looks weird
        if(name[0]!= '\0'){
            if (strlen(name) <= 20)
                strcpy(m_itemName, name);
            else {
                strncpy(m_itemName, name, 20);
                m_itemName[20] = '\0';
            }
        }
        }
    //public:
        //set the Item to Empty State
        //m_itemName to
        //etting the m_itemName to a blank string (first character set to null)
        void Item::setEmpty(){
        m_price = 0.0;
        m_taxed = false;
        m_itemName[0] = '\0';
        //TODO::check the init
        }

/*    Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName method
 * and sets the m_price and m_taxed attributes to the corresponding arguments.
 * If price is less than 0 or name is null, then the Item is set to a recognizable invalid empty state (safe empty state).*/
        void Item::set(const char* name, double price, bool taxed){
            if (price < 0 ||name == nullptr){
                setEmpty();
            }else{
                m_price = price;
                m_taxed = taxed;
                setName(name);
            }
        }

/*    Prints an item in the following format.
    */
    //If the Item is valid:
/*
            Newline*/
        void Item::display()const{
            if(isValid()){
                //Milk 2%.............
                cout <<"| " ;

                cout.setf( ios::left );
                cout.fill('.');
                cout.width(20);
                cout << m_itemName;
                cout.unsetf( ios::left );


                cout << " | " ;
                cout.setf( ios::right );
                cout.setf( ios::fixed );
                cout.precision( 2 );
                cout.fill(' ');
                cout.width(7);
                cout << m_price;
                cout.unsetf( ios::right );
                cout.unsetf( ios::fixed );

                cout << " | " ;

//                if(m_taxed){
//                    cout << "Yes" ;
//                }else{
//                    cout << "No" ;
//                }
                (m_taxed)?cout << "Yes":cout << "No ";
                cout << " |" << endl;
            }else{
                cout <<"| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
            }
        }

        //Returns true if the Item is not set to the empty state (As done in setEmpty function).
        //This function can not modify its owner.

        bool Item::isValid()const{
            bool ret = true;
            //TODO : do something here but no idea everything look weird
            if (m_price == 0.0 && m_taxed && m_itemName[0] == '\0'){
                ret = false;
            }
            return ret;
        }

        //Returns the m_price attribute;
        double Item::price()const{
            return m_price;
        }

        //Returns the product of m_price and 0.13(define a constant double value for this tax rate).
        // Or it returns 0.0 if the m_taxed is false.
        double Item::tax()const{
            double ret = 0.0;
            if(m_taxed){
               ret = m_price*0.13;
            }
            //return (!m_taxed)? 0.0 :m_price*m_taxed;
            return ret;
        }

}