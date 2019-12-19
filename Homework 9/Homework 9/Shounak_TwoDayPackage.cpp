//
//  TwoDayPackage.cpp
//  Homework 9
//Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/2/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "TwoDayPackage.h"

using namespace std;

TwoDayPackage::TwoDayPackage(User a,User b, int weight, float charge,float flat):Package(a,b, weight, charge){
    extraCharge = flat;
    type = "2 day Delivery";
}

float TwoDayPackage::getextraFee(){
    return extraCharge;
}
//Add the flat charge to the normal charge and calculate the result directly
float TwoDayPackage::calculateCost(){
    return (extraCharge+Package::rate)*weight;
}

string TwoDayPackage::getTypeofDelivery(){
    return type;
}
