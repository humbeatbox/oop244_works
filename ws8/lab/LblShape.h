//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-13 Creat this file
//Done on

//

#ifndef WS8_LBLSHAPE_H
#define WS8_LBLSHAPE_H

#include "Shape.h"

namespace seneca {

    class LblShape:public Shape {
        char* m_label{};
    protected:
        char* label()const;
    public:
        LblShape() = default;
        LblShape(const char*);
        virtual ~LblShape();

        void getSpecs(std::istream &istr);
    };


} // seneca
#endif //WS8_LBLSHAPE_H
