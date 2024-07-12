//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-07 Creat this file
//Done on

//

#include "Truck.h"

using namespace seneca;
namespace seneca{

    Truck::Truck(string LPNumber, size_t year,double capacity,string address) : MotorVehicle(LPNumber,year),m_capacity(capacity),m_cargo(0) {
        moveTo(address.c_str());
    }

    bool Truck::addCargo(double cargo) {
        bool ret{};
        if(cargo != 0 && m_capacity != m_cargo){
            if(m_capacity > (m_cargo+cargo)){
                m_cargo += cargo;
                ret = true;
            }else if(m_capacity < (m_cargo+cargo)){
                m_cargo = m_capacity;
                ret = true;
            }
        }
        return ret;
    }

    bool Truck::unloadCargo() {
        if (m_cargo > 0) {
            m_cargo = 0;
            return true;
        }
        return false;
    }
    ostream& Truck::write(ostream& os)const{
        MotorVehicle::write(os) << " | " << m_cargo << "/" << m_capacity;
        return os;
    }

    istream& Truck::read(istream &in) {
        MotorVehicle::read(in);
        cout <<"Capacity: ";
        cin >> m_capacity;
        cout << "Cargo: ";
        cin >> m_cargo;
        return in;
    }
    std::ostream& operator<<(std::ostream &os,const Truck &T){
        return T.write(os);
    }
    std::istream& operator>>(std::istream &is,Truck &T){
        return T.read(is);
    }

}