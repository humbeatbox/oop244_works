//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-19 Creat this file
//Done on 2024-05-22
//
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace seneca {

    int noOfEmployees;
    Employee* employees;

    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }
    // loads a employee structure with its values from the file
    // TODO: Finish the implementation of the 1 arg display function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(struct Employee* emp) {
    bool ok = false;
    char name[128];
    if(read(emp->m_empNo) && read(emp->m_salary) && read(name)){
        emp->m_name = new char [strlen(name)+1];//the real name length of employees
        strcpy(emp->m_name,name);
        ok = true;
    }
    return ok;
}


// TODO: Finish the implementation of the 0 arg load function
bool load() {
    bool ok = false;
    int i = 0;
    if (openFile(DATAFILE)) {
        noOfEmployees = noOfRecords();
        employees =  new struct Employee[noOfEmployees+1];
        for (i = 0; i<noOfEmployees ;i++) {
            load(&employees[i]);
        }
        if (i != noOfEmployees){
            cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
        }
        ok = true;
        closeFile();
    }
    else {
        cout << "Could not open data file: " << DATAFILE<< endl;
    }
    return ok;
}

// TODO: Implementation for the display functions go here
    void display(const struct Employee* emp){
        cout << emp->m_empNo << ": " << emp->m_name << ", " << emp->m_salary << endl;
    }
    void display(){
        cout << "Employee Salary report, sorted by employee number\n"
                "no- Empno, Name, Salary\n"
                "------------------------------------------------" << endl;
        sort();
        int i = 0;
        for (i = 0; i < noOfEmployees; ++i) {
            cout << i+1 << "- " ;
            display(&employees[i]);
        }
    }

// TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory(){
        int i = 0;
        for (i = 0; i < noOfEmployees; ++i) {
            delete[] employees[i].m_name;
            employees[i].m_name = nullptr;
        }
        delete[] employees;
        employees = nullptr;
    }
}