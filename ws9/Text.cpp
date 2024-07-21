#include <fstream>
#include "Text.h"
using namespace std;
namespace seneca {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
       fin.close();//?????
      return len;
   }

    Text::Text(const Text &right){
        if (right.m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
            m_filename = new char[strlen(right.m_filename) + 1];
            strcpy(m_filename, right.m_filename);
        }

        if (right.m_content != nullptr) {
            delete[] m_content;
            m_content = nullptr;
            m_content = new char[strlen(right.m_content) + 1];
            strcpy(m_content,right.m_content);
        }
    }

    Text& Text::operator=(const Text &right) {
       if(this == &right){
           return *this;
       }
       if(right.m_filename != nullptr){
           delete[] m_filename;
           m_filename = nullptr;
           m_filename = new char[strlen(right.m_filename) + 1];
           strcpy(m_filename,right.m_filename);
       }
       if(right.m_content != nullptr){
           delete[] m_content;
           m_content = nullptr;
           m_content = new char[strlen(right.m_content) + 1];
           strcpy(m_content,right.m_content);
       }
        return *this;
    }

    Text::~Text() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_content = nullptr;
    }

    void Text::read() {
        int fileLength = getFileLength();
        m_content = new char[fileLength + 1];
        ifstream fin(m_filename);
        int len = 0;
        while (fin) {
            m_content[len] = fin.get();
            len += !!fin;
        }
        m_content[fileLength] = '\0';
    }

    void Text::write(ostream &os) const {
        if(m_content != nullptr ){
            os << m_content;
        }
    }

    const char &Text::operator[](int index) const {
//        return (index >= 0 && index < strlen(m_content)) ? m_content[index] : m_content[strlen(m_content)];
//        return (index >= 0 && index < strlen(m_content)) ? m_content[index] : '\0';
        return m_content[index];//?????
    }

    Text::Text(const char *filename) {
        if(filename != nullptr){
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename,filename);
            read();
        }
    }

    std::ostream& operator<<(std::ostream& os,const Text &T){
       T.write(os);
        return os;
   }

}