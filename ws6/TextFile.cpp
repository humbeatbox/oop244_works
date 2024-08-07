//Name:Hsiao-Kang Chang
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-06-25 Creat this file
//Done on 07-04

//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
using namespace std;
namespace seneca {
    Line::operator const char* () const {
        return m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }

    Line::~Line() {
        delete[] m_value;
        m_value = nullptr;
    }
    //the below is for TextFile

    //deletes the m_textLines dynamic array and sets is to nullptr deletes the m_filename dynamic Cstring
    //and sets is to nullptr sets m_noOfLines attribute to zero.
    void TextFile::setEmpty(){
        if(m_textLines != nullptr){
            delete[] m_textLines;
            m_textLines = nullptr;
        }
        if(m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        m_noOfLines = 0;
    }
    //If the isCopy argument is false, dynamically allocates a Cstring in m_filename and copies the content of the fname argument into it.
    //If the isCopy argument is true, dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it.
    void TextFile::setFilename(const char* fname, bool isCopy){
        if(m_filename != nullptr){
            delete[] m_filename;
            m_filename = nullptr;
        }
        if(isCopy){
            m_filename = new char[strlen(fname) + 3];
            strcpy(m_filename, "C_");
            strcat(m_filename,fname);
        } else{
            m_filename = new char[strlen(fname) + 1];
            strcpy(m_filename, fname);
        }
    }
       void TextFile::setNoOfLines(){
        ifstream fin;
        fin.open(m_filename);
        if(fin.is_open()){
            m_noOfLines = 0;
            char ch;
            while (fin.get(ch)){
                if(ch == '\n'){
                    m_noOfLines++;
                }
            }
            fin.close();
            m_noOfLines++;//in case last line no \n
        }
        if(m_noOfLines == 0){
            setEmpty();
        }
    }
    void TextFile::loadText(){
        if(m_textLines != nullptr){
            delete[] m_textLines;
            m_textLines = nullptr;
        }
        //if reuse this function we need to check it's safe state
        if(m_filename){
            m_textLines = new Line[m_noOfLines];ifstream fin;
            fin.open(m_filename);
            if(fin.is_open()){
                string str;
                int lineNo = 0;
                while (getline(fin, str)) {
                    m_textLines[lineNo++] = str.c_str();
                }
                m_noOfLines = lineNo + 1;//in case
                fin.close();
            }
        }

    }
    //Saves the content of the TextFile under a new name.
    void TextFile::saveAs(const char *fileName)const{
        ofstream f(fileName);
        if(f.is_open()){
            for (unsigned i = 0; i < (lines() -1) ; i++) {
                f << m_textLines[i].m_value << endl;
            }
            f.close();
        }
    }
    TextFile::TextFile(unsigned pageSize):m_pageSize(pageSize){
        setEmpty();
    }
    //Then, if the filename is not null, it will set the filename, set the number of Lines and load the Text (using the corresponding private methods.)
    TextFile::TextFile(const char* filename, unsigned pageSize):m_pageSize(pageSize){
        setEmpty();
        if(filename != nullptr && filename[0] != '\0'){
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }
/*  Initializes the m_pageSize attribute using the m_pageSize of the incoming TextFile object
 * and all the other attributes to nullptr and zero.
    If the incoming Text object is in a valid State, performs the following tasks to copy the textfile and the content safely:
    Sets the file-name to the name of the incoming TextFile object (isCopy set to true) See setFilename()
    Saves the content of the incoming TextFile under the file name of the current TextFile
    set the number of lines loads the Text*/
    TextFile::TextFile(const TextFile& right):m_pageSize(right.m_pageSize){
        setEmpty();
        if(right.m_filename){
            setFilename(right.m_filename,true);
            right.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    //If the current and the incoming TextFiles are valid
    //it will first delete the current text and then overwrites the current file and data by the content of the incoming TextFile.
    TextFile& TextFile::operator=(const TextFile& src){
        if(this != &src && *this && src){//not self-assignment check and not empty state
            delete[] m_textLines;
            m_textLines = nullptr;
            src.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }
    TextFile::~TextFile(){
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
    }
    std::ostream& TextFile::view(std::ostream& ostr)const{
        if(m_filename) {
            cout << m_filename << "\n==========\n";
            for (unsigned i = 1; i < lines(); i++) {
                cout << m_textLines[i-1].m_value << endl;
                if (i % m_pageSize ==0) {
                    cout << "Hit ENTER to continue...";
                    char ch = ' ';
                    //flush it
                    while(ch != '\n') {
                        ch = getchar();
                    }
                    //get the EOF
                    char cstr[3];
                    scanf("%[^\n]", cstr);
                }
            }
        }
        return ostr;
    }
    //Receives a filename from istr to set the file name of the TextFile.
    //Then sets the number of lines and loads the Text.
    //When done it will return the istr;
    std::istream& TextFile::getFile(std::istream& istr){
        char str[100];
        istr>>str;
        setFilename(str);
        setNoOfLines();
        loadText();
        return istr;
    }
    TextFile::operator bool()const{
        return m_filename;
        //TODO:check the m_filename can present the empty state or not
    }
    unsigned TextFile::lines()const{
        return m_noOfLines;
    }
    const char* TextFile::name()const{
        return m_filename;
    }

    const char* TextFile::operator[](unsigned index)const{
        return (m_textLines) ? m_textLines[index % (m_noOfLines -1 )].m_value : nullptr;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text){
        return text.view(ostr);
    }
    std::istream& operator>>(std::istream& istr, TextFile& text){
        return text.getFile(istr);
    }
}