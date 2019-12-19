//
//  OvernightPackage.cpp
//  Homework 9
//Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/2/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "OvernightPackage.h"

using namespace std;

OvernightPackage::OvernightPackage(User a,User b, int weight, float charge,float flat):Package(a,b, weight, charge){
    flatcharge = flat;
    type = "Overnight delivery";
}

float OvernightPackage::getExtra(){
    return flatcharge;
}
//Add the flat charge to the normal charge and calculate the result directly
float OvernightPackage::calculateCost(){
    return (flatcharge+Package::rate)*weight;
}

string OvernightPackage::getTypeofDelivery(){
    return type;
}
