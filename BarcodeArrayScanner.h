/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * Assignment 4 (Resubmission): Barcode scanner using Array
 * */

#ifndef _ARRAYSCANNER_
#define _ARRAYSCANNER_
#include "Scanner.h"

template <class T>
class ArrayScanner : Scanner<T>
{
  private:
    T *products = new T[2000000];
    int productCount = 0;

  public:
    T scan(T &product)
    {
        T result = product;
        for (int i = 0; i < productCount; i++)
        {
            if (products[i] == product)
            {
                result = products[i];
                break;
            }
        }
        return result;
    };

    void insert(T &product)
    {
        products[productCount++] = product;
    };

    ~ArrayScanner()
    {
        delete products;
    }
};
#endif //_ARRAYSCANNER_