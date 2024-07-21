#include "HtmlText.h"
namespace seneca {
    HtmlText::HtmlText(const char *filename, const char* title) : Text(filename){
        if(title != nullptr){
            m_title = new char[strlen(title) + 1];
            strcpy(m_title,title);
        }
    }

    void HtmlText::write(std::ostream &os) const {
        //Text::write(os);

    }

    HtmlText::HtmlText(HtmlText &right) : Text(right){
        if(right.m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
            m_title = new char[strlen(right.m_title) + 1];
            strcpy(m_title, right.m_title);
        }
    }

    HtmlText::~HtmlText() {
        delete[] m_title;
        m_title = nullptr;
    }

    HtmlText &HtmlText::operator=(const HtmlText &right) {
        if(this == &right){
            return *this;
        }
        Text::operator=(right);
        delete[] m_title;
        m_title = nullptr;
        m_title = new char[strlen(right.m_title) + 1];
        strcpy(m_title,right.m_title);

        return *this;
    }
}