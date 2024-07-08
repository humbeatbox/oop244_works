//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-07 Creat this file
//Done on

//

#ifndef WS7_TRUCK_H
#define WS7_TRUCK_H
#include "MotorVehicle.h"

namespace seneca{
    class Truck : public MotorVehicle{
        double m_capacity{};
        double m_cargo{};
    public:
        Truck(string LPNumber, size_t year,double capacity,string address);
        bool addCargo(double cargo);
        bool unloadCargo();
        ostream& write(ostream& os);
        istream& read(istream& in);
    };
    std::ostream& operator<<(std::ostream&,Truck&);
    std::istream& operator>>(std::istream&,Truck&);
}
#endif //WS7_TRUCK_H
