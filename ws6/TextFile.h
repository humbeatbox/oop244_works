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
        //holds the address of the dynamically allocated Cstring (to hold a line of the text file)
        char* m_value{ nullptr };
        //Returns the address held in the m_value attribute.
        operator const char* ()const;
        //Dynamically allocates memory in m_value and copies the Cstring pointed by lineContent into it.
        Line& operator=(const char*);
        //Initializes the m_value attribute to nullptr.
        Line() {}
        //Makes sure all the allocated memory is freed.
        ~Line();

        friend class TextFile;
        // copy and copy assignment prevention goes here
        Line(const Line&) = delete;
        Line& operator=(const Line&) = delete;
    };

    class TextFile {
        //A pointer to hold the dynamic array of Lines. This attribute should be initialized to nullptr
        Line* m_textLines{};
        //A pointer to hold the dynamic Cstring holding the name of the file. This attribute should be initialized to nullptr
        char* m_filename{};
        //An unsigned integer to be set to the number of lines in the file.
        unsigned m_noOfLines;
        //The page size is the number of lines that should be displayed on the screen before the display is paused.
        //After these lines are displayed, the user must hit enter for the next page to appear.
        unsigned m_pageSize;
        void setEmpty();
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char *fileName)const;

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
