//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-19 Creat this file
//Done on

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
    bool load(const struct Employee* emp) {
    bool ok = false;
    char name[128];
    /* if reading of employee number, salay and name are successful
            allocate memory to the size of the name + 1
            and keep its address in the name of the Employee Reference

            copy the name into the newly allocated memroy

            make sure the "ok" flag is set to true
       end if
    */
    if(emp->m_name != nullptr){
        read(employees->m_empNo);
        read(employees->m_salary);
        read(name);
        employees->m_name = new char [strlen(name)+1];//the real name length of employees
        strcpy(employees->m_name,name);
        ok = true;
    }

    return ok;
}


// TODO: Finish the implementation of the 0 arg load function
bool load() {
    bool ok = false;
    int i = 0;
    if (openFile(DATAFILE)) {
    //FILE* pFile = fopen(DATAFILE, "r");
        /*
         Set the noOfEmployees to the number of recoreds in the file.
         dyanamically allocated an array of employees into the global
         Employee pointer; "employees" to the size of the noOfEmployees.

         In a loop load the employee records from the file into
         the dynamic array.

         If the number of the records does not match the number of reads
            print the message
           "Error: incorrect number of records read; the data is possibly corrupted"
         Otherwise
            set the ok flag to true
         End if

         close the file
         */
        noOfEmployees = noOfRecords();
        employees =  new struct Employee[noOfEmployees+1];
        for (i = 0; i<noOfEmployees+1 ;i++) {
            load(&employees[i]);
            //read(employees[i].m_name);
//            read(employees[i].m_empNo);
//            read(employees[i].m_salary);
            //cout <<"index " << i<< " emp num is"<< employees[i].m_empNo << endl;
        }

        if (i != noOfRecords()){
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
        cout << emp->m_empNo << ", " << emp->m_name << ", " << emp->m_salary << endl;
    }

    void display(){
        cout << "Employee Salary report, sorted by employee number\n"
                "no- Empno, Name, Salary\n"
                "------------------------------------------------" << endl;
        sort();
        int i = 0;
        for (i = 0; i < noOfEmployees; ++i) {
            cout << i << employees[i--].m_empNo << employees[i--].m_name << employees[i-1].m_salary << endl;
        }


    }

// TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory(){
        delete[] employees;
        employees = nullptr;
    }


}