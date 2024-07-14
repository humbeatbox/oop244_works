//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-14 Creat this file
//Done on

//

#include "Line.h"

using namespace seneca;
using namespace std;
namespace seneca{
//    Line::Line():LblShape(){
//
//    }

//    Line::Line(char* label, size_t length) : LblShape(label),m_length(length){
    Line::Line(string label, size_t length) : LblShape(label),m_length(length){
    }

    void Line::getSpecs(std::istream &istr) {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore(1000,'\n');
    }

    void Line::draw(ostream &os) const {
        if(m_length>0 && label() != nullptr){
            os << label() << endl;
            for (int i = 0; i < m_length; ++i) {
                os << "=";
            }
        }
    }

}