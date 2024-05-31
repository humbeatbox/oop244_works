//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-31 Creat this file
//Done on

#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"

#define PI 3.14159265

using namespace std;
namespace seneca {
    //private
    void Canister::setName(const char* Cstr){}
    bool Canister::isEmpty()const{
        bool ret = false;
        return ret;
    }
    bool Canister::hasSameContent(const Canister& C)const{
        bool ret = false;
        return ret;
    }
    //--public
    Canister::Canister(){}
    Canister::Canister(const char* contentName){}
    Canister::Canister(double height, double diameter,const char* contentName){}
    Canister::~Canister(){}
    Canister& Canister::setContent(const char* contentName){
        return *this;
    }
    Canister& Canister::pour(double quantity){
        return *this;
    }
    Canister& Canister::pour(Canister&){
        return *this;
    }
    double Canister::volume()const{
        double ret = 0.0;
        return ret;
    }
    std::ostream& Canister::display()const{
        return cout;
    }
    double Canister::capacity()const{
        double ret = 0.0;
        return ret;
    }
    void Canister::clear(){}
}