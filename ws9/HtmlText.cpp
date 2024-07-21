#include <iostream>
#include <cstring>
#include "HtmlText.h"

using namespace std;
using namespace seneca;
namespace seneca {
    HtmlText::HtmlText(const char *filename, const char* title) : Text(filename),m_title(nullptr){
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
            copyTitle(right.m_title);
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
        copyTitle(right.m_title);
        return *this;
    }

    void HtmlText::copyTitle(const char *title) {
        delete[] m_title;
        m_title = nullptr;
        if (title != nullptr) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        } else {
            m_title = nullptr;
        }
    }
}