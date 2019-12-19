//
//  Polynomial_Shounak.h
//  Homework 7
//
//  Created by Shounak Rangwala on 10/22/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#ifndef Polynomial_Shounak_h
#define Polynomial_Shounak_h
using  namespace std;
class Polynomial{
    friend ostream & operator<<(ostream&, Polynomial &);
public:
    Polynomial();
    void setArray ();
    Polynomial operator+(const Polynomial &);
    Polynomial operator-(const Polynomial &);
    void operator=(const Polynomial &);
    Polynomial operator*(const Polynomial &);
    void operator+=(const Polynomial &);
    void operator-=(const Polynomial &);
    void operator*=(const Polynomial &);
private:
    int array[10];
};


#endif /* Polynomial_Shounak_h */
