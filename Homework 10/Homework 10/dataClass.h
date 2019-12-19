//
//  dataClass.h
//  Homework 10
//
//  Created by Shounak Rangwala on 11/9/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef dataClass_h
#define dataClass_h
#include <string>
#include <iostream>
using namespace std;
class Data{
public:
    Data();
    Data(int,string );
    int getItemNumber ();
    string getName ();
protected:
    string productName;
    int itemNumber;
};
#endif /* dataClass_h */
