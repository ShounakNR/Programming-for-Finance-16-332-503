//
//  dataClass.cpp
//  Homework 10
//
//  Created by Shounak Rangwala on 11/9/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "dataClass.h"
#include <string>
using namespace std;
Data::Data(){
    
}
Data::Data(int Number, string  itemName ){
    itemNumber = Number;
    productName = itemName;
    
}

int Data::getItemNumber(){
    return itemNumber;
}

string Data::getName(){
    return productName;
}
