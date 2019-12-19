//
//  User.h
//  Homework 9
//Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/2/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef User_h
#define User_h
#include <string>

using namespace std;

/*Declaration of class User.*/
class User {
public:
    User();
    User(string, string, string, string, string);
    string getName();
    string getAddress();
    string getCity();
    string getState();
    string getZip();
private:
    /*Member variables.*/
    string name;
    string address;
    string city;
    string state;
    string zipCode;
};

#endif /* User_h */
