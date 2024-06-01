//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-26 Creat this file
//Done on 2024-05-27

//

#include "Item.h"
#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
namespace seneca {


        //for set the m_itemName
        void Item::setName(const char* name){
        if(name[0]!= '\0'){
            if (strlen(name) <= 20)
                strcpy(m_itemName, name);
            else {
                strncpy(m_itemName, name, 20);
                m_itemName[20] = '\0';
            }
        }
        }

        //set the Item to Empty State
        //Setting the m_itemName to a blank string
        void Item::setEmpty(){
        m_price = 0.0;
        m_taxed = false;
        m_itemName[0] = '\0';
        }

/*Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName method
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

        void Item::display()const{
            if(isValid()){
                cout <<"| " ;
                cout.setf( ios::left );
                cout.fill('.');
                cout.width(20);
                cout << m_itemName;
                cout.unsetf( ios::left );


                cout << " | " ;
//              cout.setf( ios::right );
//              cout.setf( ios::fixed );
                cout << right << fixed;
                cout.precision( 2 );
                cout.fill(' ');
                cout.width(7);
                cout << m_price;
//                cout.unsetf( ios::right );
                cout.unsetf( ios::fixed );
                cout << left;


                cout << " | " ;
                (m_taxed)?cout << "Yes":cout << "No ";
                cout << " |" << endl;
            }else{
                cout <<"| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
            }
        }

        //safe state check
        bool Item::isValid()const{
            /*bool ret = true;
            if (m_price == 0.0 && !m_taxed && m_itemName[0] == '\0'){
                ret = false;
            }
            return ret;*/
            return m_itemName[0];//we just need to verify the name
        }

        //Returns the m_price attribute;
        double Item::price()const{
            return m_price;
        }

        //Returns the product of m_price and 0.13(define a constant double value for this tax rate).
        //Or it returns 0.0 if the m_taxed is false.
        double Item::tax()const{
            return (m_taxed)? m_price*0.13:0.0;
        }

}
