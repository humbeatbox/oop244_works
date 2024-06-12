//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-06-10 Creat this file
//Done on

//

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance ) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }

    std::ostream& Account::display() const{
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if(~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }
    //if the account is valid return true
    Account::operator bool() const {
        return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
    }
    //return m_number
    Account::operator int() const {
        return m_number;
    }
    //return m_balance
    Account::operator double() const {
        return m_balance;
    }

    bool Account::operator~() const{
        return (m_number == 0);
    }

    Account& Account::operator=(int input) {
        return *this;
    }
    Account& Account::operator =(const Account&){
        return *this;
    }

    Account& Account::operator+=(double){
        return *this;
    }

    Account& Account::operator-=(double) {
        return *this;
    }

    Account& Account::operator<<(const Account &) {
        return *this;
    }

    Account& Account::operator>>(const Account &) {
        return *this;
    }

    Account& Account::operator+(const Account &) {
        return *this;
    }

    double operator+(const Account& left, const Account& right) {
        return 0.0;
    }
    double& operator+=(double& dbl, const Account &) {
        return dbl;
    }

}