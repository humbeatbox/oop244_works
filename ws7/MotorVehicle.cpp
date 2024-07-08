//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-07 Creat this file
//Done on

//
#include <cstring>
#include <iostream>
#include <iomanip>
#include "MotorVehicle.h"

using namespace std;
using namespace seneca;
namespace seneca{
    MotorVehicle::MotorVehicle(string LPNumber,size_t year){
        strcpy(m_lpNumber, LPNumber.c_str());
        m_lpNumber[8] = '\0';
        strncpy(m_address, "Factory", 63);
        m_address[63] = '\0';
        m_year = year;
    }
    void MotorVehicle::moveTo(const char* address){
        if(address != nullptr && strcmp(m_address,address) != 0 ) {//the content of address is different
            cout << "| "
                 << setw(8) << right
                 << m_lpNumber
                 << "| |"
                 << setw(20) << m_address
                 << "--->"
                 << setw(20) << left << address
                 << "|" << endl;
            strncpy(m_address, address, 64);
            m_address[63] = '\0';
        }
    }
    ostream& MotorVehicle::write(ostream& os)const{
        cout << "| " << m_year << " | " << m_lpNumber << " | " << m_address;
        return os;
    }
    istream& MotorVehicle::read(istream& in){
        cout <<"Built year: ";
        cin >> m_year;
        cout << "License plate: ";
        cin >> m_lpNumber;
        cout << "Current location: ";
        cin >> m_address;
        return in;
    }
    std::ostream& operator<<(std::ostream &os,const MotorVehicle &M){
        return M.write(os);
    }
    std::istream& operator>>(std::istream &is,MotorVehicle& M){
        return M.read(is);
    }
}