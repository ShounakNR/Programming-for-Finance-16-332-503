//
//  Package.cpp
//  Homework 9
//Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/2/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "Package.h"
#include <string>

using namespace std;

Package::Package(User a, User b, int ounces, float ratePerOunces){
    sender=a;
    receiver=b;
    weight = ounces;
    rate = ratePerOunces;
    type = "Regular Delivery";
}

float Package::calculateCost(){
    return weight*rate;
}

User Package::getSender(){
    return sender;
}
User Package::getReceiver(){
    return receiver;
}

string Package::getTypeofDelivery(){
    return type;
}

int Package::getWeight(){
    return weight;
}
