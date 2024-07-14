//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-13 Creat this file
//Done on 2024-07-14
//
#include <ostream>
#include "Shape.h"
namespace seneca {
    std::ostream& operator<<(std::ostream& os, const Shape& right) {
        right.draw(os);
        return os;
    }
    std::istream& operator>>(std::istream& is, Shape& right) {
        right.getSpecs(is);
        return is;
    }
} // seneca
