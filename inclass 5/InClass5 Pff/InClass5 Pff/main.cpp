//
//  main.cpp
//  InClass5 Pff
//
//  Created by Shounak Rangwala on 10/19/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
using namespace std;

#include "IntegerSet.h"
int main(int argc, const char * argv[]) {
    IntegerSet a;
    IntegerSet b;
    IntegerSet c;
    IntegerSet d;
    
    cout << "Enter set A:\n";
    a.inputSet();
    cout << "\nSet A is:\n";
    a.printSet();
    
    cout << "\nEnter set B:\n";
    b.inputSet();
    cout << "\nSet B is:\n";
    b.printSet();
    
    /* Write call to unionOfSets for object a, passing b as argument and assigning the result to c */
    c = a.unionOfSets(b);
    cout << "\nUnion of A and B is:\n";
    c.printSet();
    
    /* Write call to intersectionOfSets for object a, passing b as argument and assigning the result to d */
    d=a.intersectionOfSets(b);
    cout << "\nIntersection of A and B is:\n";
    d.printSet();

    return 0;
}
