//
//  ThreeDimensional.h
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef ThreeDimensional_h
#define ThreeDimensional_h

#include "Shape.h"

class ThreeDimensional :public Shape{
public:
    ThreeDimensional (int=0,int=0,int=0);
    void setZ (int);
    int getZ();
protected:
    int z;
};

#endif /* ThreeDimensional_h */
