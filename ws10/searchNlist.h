#ifndef SENECA_SEARCHNLIST_H_
#define SENECA_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"

using namespace std;
namespace seneca {

    /*
     * In this template it will search T1 and compare result will add into to Collection.
     * @tparam T1 Type of the elements in the array must need support comparison (==) with type `T2`, otherwise it will break in compile time.
     * @tparam T2 Type of the elements ust need support comparison (==) with type `T1`.
     * @param T1 array should support T2 type (in the array)
     * @param arr should point to the T1 type array
     * @param arr_size should input the size of array
     * @param key should be in the T1 array
     * @return if search result over 0, it will return true else return false.
     * */
    template <typename T1,typename T2>
    bool search(Collection<T1>& C,const T1* arr,const int arr_size,T2 key){
        bool ret{};

        for (int i = 0; i < arr_size; ++i) {
            if(arr[i] == key){
                C.add(arr[i]);
                ret = true;
            }
        }
        return ret;
    }

    /*
     * This function will print the elements in the array arr
     * @param title should be the c type string
     * @param arr point to the T type array
     * @param arr_size Size of the T type array
     * */
    template <typename T>
    void listArrayElements(const char* title,const T* arr,const int arr_size){
        cout << title << endl;
        for (int i = 0; i < arr_size; ++i) {
            cout << i+1 << ": ";
            cout << arr[i] << endl;
        }
    }
}

#endif // !SENECA_SEARCHNLIST_H_