//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-14 Creat this file
//Done on 2024-07-14
//
#ifndef WS8_LINE_H
#define WS8_LINE_H
#include "LblShape.h"

using namespace seneca;
namespace seneca{
    class Line : public LblShape{
        size_t m_length{};
    public:
        Line() = default;
        Line(std::string ,size_t);
        void getSpecs(std::istream &istr) override;
        virtual void draw(std::ostream&) const override;
    };
}
#endif //WS8_LINE_H
