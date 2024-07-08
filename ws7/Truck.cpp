//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-07 Creat this file
//Done on

//

#include "Truck.h"

using namespace seneca;
namespace seneca{

    Truck::Truck(string LPNumber, size_t year,double capacity,string address) : MotorVehicle(LPNumber,year) {
        m_cargo = capacity;
        moveTo(address.c_str());
        //TODO:check use moveTo is correct or not
    }

    bool Truck::addCargo(double cargo) {
        if((cargo + m_cargo) <= m_capacity){
            m_cargo +=cargo;
            return true;
        }
        return false;
    }

    bool Truck::unloadCargo() {
        if (m_cargo > 0) {
            m_cargo = 0;
            return true;
        }
        return false;
    }
    ostream& Truck::write(ostream& os){
        MotorVehicle::write(os) << " | " << m_cargo << "/" << m_capacity;
        //cout << "| " << m_year << " | " << m_address << " | " << m_cargo << "/" << m_capacity;
        //TODO:check can i use like this
        return os;
    }

    istream &Truck::read(istream &in) {
        MotorVehicle::read(in);
        cout <<"Capacity: \n";
        cin >> m_capacity;
        cout << "Cargo: \n";
        cin >> m_cargo;
        return in;
    }
    std::ostream& operator<<(std::ostream &os,Truck &T){
        return T.write(os);
    }
    std::istream& operator>>(std::istream &is,Truck &T){
        return T.read(is);
    }

}