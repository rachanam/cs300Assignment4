/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * Assignment 4 (Resubmission): Scanner base class
 * */

#ifndef _SCANNER_
#define _SCANNER_
template <class T>
class Scanner
{
  public:
    virtual T scan(T &product) = 0;
    virtual void insert(T &product) = 0;
    ~Scanner() {}
};

#endif //_SCANNER_