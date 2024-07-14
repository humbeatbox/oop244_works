//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-07-13 Creat this file
//Done on

//

#include "LblShape.h"
#include <istream>
using namespace seneca;
using namespace std;
namespace seneca{
    char* LblShape::label() const {
        return m_label;
    }
//LblShape::LblShape(const char *label) {
    LblShape::LblShape(const string label) {
//        if(label != nullptr){
        if(!label.empty()){
            m_label = new char[strlen(label.c_str()) + 1];
            strcpy(m_label,label.c_str());
        }
    }

    LblShape::~LblShape() {
        delete[] m_label;
        m_label = nullptr;
    }

    //TODO: check Shape::getSpecs???
    void LblShape::getSpecs(std::istream& istr){
        char tmp[255];
        istr.getline(tmp,255,',');

        delete[] m_label;
        m_label = new char[strlen(tmp) + 1];
        strcpy(m_label, tmp);
    }
}

