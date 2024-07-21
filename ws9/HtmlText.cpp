#include <iostream>
#include "HtmlText.h"

using namespace std;
using namespace seneca;
namespace seneca {
    HtmlText::HtmlText(const char *filename, const char* title) : Text(filename){
        if(title != nullptr){
            m_title = new char[strlen(title) + 1];
            strcpy(m_title,title);
        }
    }

    void HtmlText::write(std::ostream &os) const {
        bool MS{};
        os <<"<html><head><title>";
        if(m_title != nullptr){
            os << m_title;
        }else{
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";

//        if (m_title) {
//            os << "<h1>" << m_title << "</h1>\n";
//        }
        os << "<h1>";
        if(m_title == nullptr){
            os << "No Title";
        } else{
            os << m_title;
        }
        os << "</h1>\n";

        for (int i = 0; (*this)[i] != '\0'; ++i) {
            char ch = (*this)[i];
            switch (ch) {
                case ' ':
                    if (MS) {
                        os << "&nbsp;";
                    } else {
                        MS = true;
                        os << ' ';
                    }
                    break;
                case '<':
                    os << "&lt;";
                    MS = false;
                    break;
                case '>':
                    os << "&gt;";
                    MS = false;
                    break;
                case '\n':
                    os << "<br />\n";
                    MS = false;
                    break;
                default:
                    MS = false;
                    os << ch;
            }
        }
        os << "</body>\n</html>";
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