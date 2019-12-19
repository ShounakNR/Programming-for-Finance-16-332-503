//
//  ThreeDimensional.cpp
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
using namespace std;
#include "ThreeDimensional.h"

ThreeDimensional::ThreeDimensional(int x,int y,int z):Shape(x,y){
    setZ(z);
}
void ThreeDimensional::setZ(int zCoord){
    z = zCoord;
}

int ThreeDimensional::getZ(){
    return z;
}
