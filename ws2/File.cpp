//Name:Hsiao-Kang Chang 
//Seneca email:hchang67@myseneca.ca
//Seneca Student ID:120049234
//2024-05-17 Creat this file
//Done on
#include <cstdio>
#include "File.h"

namespace seneca {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    // TODO: read functions go here

    bool read(char* name) {
        bool ret = false;

        if(fptr){
            fscanf(fptr,"%[^\n]\n",name);
            ret = true;
        }
        return ret;
    }
  bool read(int &intNum) {
      bool ret = false;
      if(fptr){
          fscanf(fptr,"%d",&intNum);
          ret = true;
      }
      return ret;
  }
    bool read(double &dulNum) {
        bool ret = false;
        if(fptr){
            fscanf(fptr,"%lf",&dulNum);
            ret = true;
        }
        return ret;
    }

}