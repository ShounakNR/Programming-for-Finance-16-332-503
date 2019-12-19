//
//  Package.h
//  Homework 9
//Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/2/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef Package_h
#define Package_h
#include <string>
#include "User.h"

using namespace std;

#include <string>

#include "User.h"
using namespace std;

class Package{
public:
    Package(User,User,int,float);
    virtual float calculateCost();
    int getWeight();
    float getRate();
    User getSender();
    User getReceiver();
    virtual string getTypeofDelivery();
    
protected:
    User sender;
    User receiver;
    int weight;
    float rate;
    string type;
};
#endif /* Package_h */
