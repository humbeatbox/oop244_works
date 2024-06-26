//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-06-25 Creat this file
//Done on

//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
using namespace std;
namespace seneca {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        delete[] m_value;
    }
    //the below is for TextFile

    //deletes the m_textLines dynamic array and sets is to nullptr deletes the m_filename dynamic Cstring and sets is to nullptr sets m_noOfLines attribute to zero.
    void TextFile::setEmpty(){
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }
    //If the isCopy argument is false, dynamically allocates a Cstring in m_filename and copies the content of the fname argument into it.
    //If the isCopy argument is true, dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it.
    void TextFile::setFilename(const char* fname, bool isCopy){
        if(isCopy){
            m_filename = new char[strlen(fname) + 3];
            strcpy(m_filename, "C_");
            strcat(m_filename, fname);
        } else{
            m_filename = new char[strlen(fname) + 1];
            strcpy(m_filename, fname);
        }
    }
    //Creates a local ifstream object to open the file with the name held in m_filename.
    //Then it will read the file, character by character, and accumulates the number of newlines in the m_noOfLines attribute.
    //In the end, it will increase m_noOfLines by one, just in case, the last line does not have a new line at the end.
    //If the number of lines is zero, it will delete the m_filename and set it to nullptr. (Setting the TextFile to a safe empty state)
    void TextFile::setNoOfLines(){
        ifstream f_file(m_filename);
        if(f_file.is_open()){
            m_noOfLines = 0;//need the init?
            string line;//tmp string
            if(getline(f_file, line)) {// not zero line
                while (getline(f_file, line)) {//when return is true
                    m_noOfLines++;
                }
                //TODO:check the getline() function is something wrong use the getchar
                m_noOfLines++;//in case
            }else{//zero line
                delete[] m_filename;
                m_filename = nullptr;
            }
        }
        /*else{
            delete[] m_filename;
            m_filename = nullptr;
        }*/

    }
    void TextFile::loadText(){
        if(m_filename){
            loadText()
        }
    }
    void TextFile::saveAs(const char *fileName)const{

    }

    TextFile& TextFile::operator=(const TextFile&){
        return *this;
    }
    TextFile::~TextFile(){

    }
    std::ostream& TextFile::view(std::ostream& ostr)const{
        return ostr;
    }
    std::istream& TextFile::getFile(std::istream& istr){
        return istr;
    }
    TextFile::operator bool()const{

    }
    unsigned TextFile::lines()const{

    }
    const char* TextFile::name()const{

    }
    const char* TextFile::operator[](unsigned index)const{

    }

}