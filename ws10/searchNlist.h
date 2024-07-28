#ifndef SENECA_SEARCHNLIST_H_
#define SENECA_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"

using namespace std;
namespace seneca {
    template <typename T1,typename T2>
    bool search(Collection<T1>& C,Collection<T1> arr[],int arr_size,T2 key){
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
    void listArrayElements(const char* title,Collection<T> arr[],int arr_size){
        cout << title << endl;
        for (int i = 0; i < arr_size; ++i) {
            cout << i+1 << ": ";
            cout << arr[i] << endl;
        }


    }
//    template <typename T1, typename T2>
//    bool search(Collection<T1>& collection, const T1* array, int size, const T2& key) {
//        bool found = false;
//        for (int i = 0; i < size; i++) {
//            if (array[i] == key) {
//                collection.add(array[i]);
//                found = true;
//            }
//        }
//        return found;
//    }
//
//    template <typename T>
//    void listArrayElements(const char* title, const T* array, int size) {
//        std::cout << title << std::endl;
//        for (int i = 0; i < size; i++) {
//            std::cout << (i + 1) << ": " << array[i] << std::endl;
//        }
//    }
}

#endif // !SENECA_SEARCHNLIST_H_