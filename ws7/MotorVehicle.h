//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-07 Creat this file
//Done on

//

#ifndef WS7_MOTORVEHICLE_H
#define WS7_MOTORVEHICLE_H
#include <cstring>
#include <iostream>

using namespace std;
namespace seneca{
    class MotorVehicle{
       char m_lpNumber[9]{};
       char m_address[64]={"Factory"};
       size_t m_year{};
    public:
        MotorVehicle(string,size_t);
        void moveTo(const char*);

        virtual ostream& write(ostream&)const;
        virtual istream& read(istream&);
    };
    std::ostream& operator<<(std::ostream&,const MotorVehicle&);
    std::istream& operator>>(std::istream&,MotorVehicle&);
}
#endif //WS7_MOTORVEHICLE_H
