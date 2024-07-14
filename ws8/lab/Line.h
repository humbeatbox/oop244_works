//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-14 Creat this file
//Done on

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
        Line(char*,size_t);
        //virtual ~Line();
//TODO: no destructor implement
        void getSpecs(std::istream &istr) override;
        virtual void draw(std::ostream&) const override;
    };

}
#endif //WS8_LINE_H
