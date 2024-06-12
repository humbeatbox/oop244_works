//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-06-10 Creat this file
//Done on

//

#ifndef WS5_ACCOUNT_H
#define WS5_ACCOUNT_H
#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        //type conversion operators
        operator bool() const;
        operator int() const;
        operator double() const;
        //Unary member operator
        bool operator ~()const;
        //Binary member operators
        Account& operator =(int);
        Account& operator =(const Account&);
        Account& operator +=(double);
        Account& operator -=(double);
        Account& operator <<(const Account&);
        Account& operator >>(const Account&);
        Account& operator +(const Account&);
    };
    double operator +(const Account&, const Account&);
    double& operator +=(double& ,const Account&);
}
#endif //WS5_ACCOUNT_H
