/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * Assignment 4 (Resubmission): Barcode scanner using BinarySearchTree
 * */

#ifndef _BSTSCANNER_
#define _BSTSCANNER_
#include "BinarySearchTree.h"
#include "Scanner.h"

template <class T>
class BSTScanner : Scanner<T>
{
  private:
    BinarySearchTree<T> bst;

  public:
    T scan(T &product)
    {
        T result = bst.search(product);
        return result;
    };
    void insert(T& item)
    {
        bst.insert(item);
    };
};
#endif //_BSTSCANNER_
