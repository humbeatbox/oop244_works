//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-14 Creat this file
//Done on 2024-07-14
//
#ifndef WS8_RECTANGLE_H
#define WS8_RECTANGLE_H
#include "LblShape.h"

using namespace seneca;
namespace seneca{
    class Rectangle : public LblShape{
        size_t m_height{};
        size_t m_width{};
    public:
        Rectangle()=default;
        Rectangle(std::string,size_t ,size_t);
        void getSpecs(std::istream &istr) override;
         void draw(std::ostream&) const override;
    };
}
#endif //WS8_RECTANGLE_H
