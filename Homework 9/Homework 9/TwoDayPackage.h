//
//  TwoDayPackage.h
//  Homework 9
//Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/2/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef TwoDayPackage_h
#define TwoDayPackage_h
#include "Package.h"

using namespace std;
class TwoDayPackage : public Package{
public:
    TwoDayPackage(User,User,int,float,float);
    float getextraFee ();
    virtual float calculateCost();
    virtual string getTypeofDelivery();
protected:
    float extraCharge;
    string type;
};

#endif /* TwoDayPackage_h */
