//
//  OvernightPackage.h
//  Homework 9
//Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/2/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef OvernightPackage_h
#define OvernightPackage_h

#include "Package.h"

using namespace std;

class OvernightPackage:public Package{
public:
    OvernightPackage(User, User, int,float,float);
    float getExtra();
    virtual float calculateCost();
    virtual string getTypeofDelivery();
protected:
    float flatcharge;
    string type;
};


#endif /* OvernightPackage_h */
