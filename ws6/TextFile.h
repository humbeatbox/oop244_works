//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-06-25 Creat this file
//Done on

//

#ifndef WS6_TEXTFILE_H
#define WS6_TEXTFILE_H
#include <iostream>
namespace seneca {
    class Line {
        char* m_value{ nullptr };
        operator const char* ()const;
        Line() {}
        Line& operator=(const char*);
        ~Line();
        friend class TextFile;
        // copy and copy assignment prevention goes here

    };

    class TextFile {
        Line* m_textLines;
        char* m_filename;
        unsigned m_noOfLines;
        unsigned m_pageSize;
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char *fileName)const;
        void setEmpty();
    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile&);
        TextFile& operator=(const TextFile&);
        ~TextFile();
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif //WS6_TEXTFILE_H
