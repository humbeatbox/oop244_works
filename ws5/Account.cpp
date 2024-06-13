//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-06-10 Creat this file
//Done on 6-23

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
        if(m_number==0.0){//new account
            if(input < 10000 || input > 99999){
                setEmpty();
            }else{
                m_number = input;
            }
        }
        return *this;
    }
    Account& Account::operator =(Account& right){
        if(bool(right)&& this->m_number==0 && this->m_balance==0){
            this->m_number = right.m_number;
            this->m_balance = right.m_balance;
            right.m_number = 0;
            right.m_balance = 0.0;
        }
        return *this;
    }

    Account& Account::operator+=(double amount){
        if(amount >= 0 && bool(*this)){//amount not negative and this account is valid
            m_balance+=amount;
        }
        return *this;
    }

    Account& Account::operator-=(double amount) {
        if(amount >= 0 && bool(*this)){//amount not negative and this account is valid
            if(m_balance>amount){//have enough money
                m_balance -= amount;
            }
        }
        return *this;
    }
    //the balance of the left account will be the sum of both and the balance of the right account will be zero.
    Account& Account::operator<<(Account& right) {
        //two account are valid and right account is not itself
        if(bool(*this) && bool(right) && this->m_number!=right.m_number) {
            this->m_balance += right.m_balance;
            right.m_balance = 0;
        }
        return *this;
    }
    //the balance of the right account will be the sum of both and the balance of the left account will be zero.
    Account& Account::operator>>(Account& right) {
        //two account are valid and right account is not itself
        if(bool(*this) && bool(right) && this->m_number!=right.m_number) {
            right.m_balance += this->m_balance;
            this->m_balance = 0;
        }
        return *this;
    }

    double operator+(const Account& left, const Account& right) {
        return (bool(left)&& bool(right))?(double(left) + double(right)):0.0;
    }

    double operator+=(double& left, const Account& right) {
        return (bool(right))?left +=double(right):left;
    }

}