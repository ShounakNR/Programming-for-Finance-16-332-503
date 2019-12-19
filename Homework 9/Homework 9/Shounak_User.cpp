//
//  User.cpp
//  Homework 9
//  Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/2/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//


#include <string>
#include "User.h"

using namespace std;
User::User() {}

User::User(string nameStr, string addressStr, string cityStr, string stateStr, string zipCodeStr) {
    name = nameStr;
    address = addressStr;
    city = cityStr;
    state = stateStr;
    zipCode = zipCodeStr;
}


string User::getName() {
    return name;
}

string User::getAddress() {
    return address;
}

string User::getCity() {
    return city;
}


string User::getState() {
    return state;
}

string User::getZip() {
    return zipCode;
}
