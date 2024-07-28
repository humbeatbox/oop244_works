#ifndef SENECA_SEARCHNLIST_H_
#define SENECA_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"

using namespace std;
namespace seneca {
    template <typename T1,typename T2>
    bool search(Collection<T1>& C,const T1* arr,int arr_size,T2 key){
        bool ret{};
        for (int i = 0; i < arr_size; ++i) {
            if(arr[i] == key){
                C.add(arr[i]);
                ret = true;
            }
        }
        return ret;
    }
    template <typename T>
    void listArrayElements(const char* title,const T* arr,int arr_size){
        cout << title << endl;
        for (int i = 0; i < arr_size; ++i) {
            cout << i+1 << ": ";
            cout << arr[i] << endl;
        }


    }
}

#endif // !SENECA_SEARCHNLIST_H_