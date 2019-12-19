//
//  main.cpp
//  Homework 7
//
//  Created by Shounak Rangwala on 10/22/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "Polynomial_Shounak.h"
using namespace std;
int main(int argc, const char * argv[]) {
    Polynomial poly1;
    poly1.setArray();
    Polynomial poly2;
    poly2.setArray();
    Polynomial poly3;
    cout << "First Polynomial is : ";
    cout << poly1 << endl;
    cout << "Second Polynomial is : ";
    cout << poly2 << endl;
    cout << "" << endl;

    cout << "Adding polynomial yields: ";
    poly3 = poly1+poly2;
    cout << poly3 << endl;
    cout << "+= the polynomial yields: ";
    Polynomial polyFirst, polySecond;
    polyFirst = poly1;
    polySecond = poly2;
    polyFirst += polySecond;
    cout << polyFirst << endl;
    cout << "" << endl;
    
    cout << "Substracting polynomial yields: ";
    poly3 = poly1-poly2;
    cout << poly3 << endl;
    cout << "-= the polynomial yields: ";
    polyFirst = poly1;
    polySecond = poly2;
    polyFirst -= polySecond;
    cout << polyFirst << endl;
    cout << "" << endl;

    cout << "Multiplying polynomial yields: ";
    poly3 = poly1*poly2;
    cout << poly3 << endl;
    cout << "*= the polynomial yields: ";
    poly1 *= poly2;
    cout << poly1 << endl;
    return 0;
}
