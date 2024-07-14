//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-13 Creat this file
//Done on

//

#ifndef WS8_SHAPE_H
#define WS8_SHAPE_H

#include <ostream>
#include <istream>
namespace seneca {

    class Shape {
    public:
    virtual void draw(std::ostream&) const = 0;
    virtual void getSpecs(std::istream&) = 0;
    virtual ~Shape() = default;
    };
    std::ostream &operator<<(std::ostream &os, const Shape& right);
    std::istream &operator>>(std::istream &is, Shape& right);

} // seneca

#endif //WS8_SHAPE_H
