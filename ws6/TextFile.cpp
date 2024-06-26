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
        //if(m_textLines){
//        delete[] m_textLines;
//        m_textLines = nullptr;
        //}
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
        ifstream fin;
        fin.open(m_filename);
        if(fin.is_open()){
            m_noOfLines = 0;//need the init?
            //string line;//tmp string
            char ch;
            while (fin.get(ch)){
                if(ch == '\n'){
                    m_noOfLines++;
                }
            }
            m_noOfLines++;//in case last line no \n
            if(m_noOfLines == 0){
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
            m_textLines = new Line[m_noOfLines];
            //TODO:Make sure m_textLine is deleted before this to prevent memory leak.
            ifstream fin;
            fin.open(m_filename);
            if(fin.is_open()){
               for (int i = 0; i < m_noOfLines; ++i) {//each line
                    //m_textLines[i] =
                }

            }

        }

    }
    //Saves the content of the TextFile under a new name.
    void TextFile::saveAs(const char *fileName)const{
        ofstream f(fileName);
        if(f.is_open()){
            for (auto i = 0; i < m_noOfLines; ++i) {
                f << m_textLines[i] << endl;
            }
        }

    }
    TextFile::TextFile(unsigned pageSize):m_pageSize(pageSize){
//        m_pageSize = pageSize;
//        setEmpty();
        m_filename = nullptr;
        m_noOfLines = 0;
        m_textLines = nullptr;
    }
    //Then if the filename is not null, it will set the filename, set the number of Lines and load the Text (using the corresponding private methods.)
    TextFile::TextFile(const char* filename, unsigned pageSize):m_pageSize(pageSize){
//        m_pageSize = pageSize;
        if(m_filename){
            setFilename(filename);
            setNoOfLines();
            loadText();
        }else{
//            setEmpty();
            m_filename = nullptr;
            m_noOfLines = 0;
            m_textLines = nullptr;
        }
    }
/*  Initializes the m_pageSize attribute using the m_pageSize of the incoming TextFile object and all the other attributes to nullptr and zero.
    If the incoming Text object is in a valid State, performs the following tasks to copy the textfile and the content safely:
    Sets the file-name to the name of the incoming TextFile object (isCopy set to true) See setFilename()
    Saves the content of the incoming TextFile under the file name of the current TextFile
    set the number of lines loads the Text*/
    TextFile::TextFile(const TextFile& right):m_pageSize(right.m_pageSize){
//        m_pageSize = right.m_pageSize;
        if(right.m_filename){
            //TODO:check my step and function call is correct or not
            setFilename(right.m_filename,true);
            //create a new file and save into new file
            right.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }else{
            setEmpty();
//            m_filename = nullptr;
//            m_noOfLines = 0;
//            m_textLines = nullptr;
        }
    }

    //If the current and the incoming TextFiles are valid
    //it will first delete the current text and then overwrites the current file and data by the content of the incoming TextFile.
    TextFile& TextFile::operator=(const TextFile& src){
        if(this != &src && *this && src){//self-assignment check and not empty state
            //TODO:check do i need to check the state?
            delete[] m_textLines;
            setEmpty();
            src.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }
    TextFile::~TextFile(){
        delete[] m_textLines;
        delete[] m_filename;
    }
    std::ostream& TextFile::view(std::ostream& ostr)const{
        if(m_filename) {
            cout << m_filename << "\n==========";
            for (int i = 0; i < m_noOfLines; ++i) {
                cout << m_textLines[i] << endl;
                if (i == m_pageSize) {//TODO:check the logic here for next page
                    cout << "Hit ENTER to continue...\n";
                    cin.ignore();//TODO: check if no more instruction
                }
            }
        }
        return ostr;
    }
    //Receives a filename from istr to set the file name of the TextFile. Then sets the number of lines and loads the Text. When done it will return the istr;
    std::istream& TextFile::getFile(std::istream& istr){
        //char* myName = nullptr;
        string str;
        //TODO:check can i use like this?
//        getline(cin,str);
        istr>>str;
        setFilename(str.c_str());
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
    //Returns the element in the m_textLine array corresponding to the index argument.
    //If the TextFile is in an empty state, it will return null. If the index exceeds the size of the array it should loop back to the beginning.
    //For example, if the number of lines is 10, the last index should be 9 and index 10 should return the first element and index 11 should return the second element.
    const char* TextFile::operator[](unsigned index)const{
        return (m_textLines && index < m_noOfLines) ? m_textLines[index % m_noOfLines] : nullptr;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text){
        return text.view(ostr);
    }
    std::istream& operator>>(std::istream& istr, TextFile& text){
        return text.getFile(istr);
    }
}