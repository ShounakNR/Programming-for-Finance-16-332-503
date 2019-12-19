//
//  Tetrahedron.h
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef Tetrahedron_h
#define Tetrahedron_h
#include "ThreeDimensional.h"

class Tetrahedron: public ThreeDimensional{
public:
    Tetrahedron(int=0,int=0,int=0,float=0);
    void setSide(float);
    float getSide();
    float getSurfaceArea();
    float getVolume();
    void print();
protected:
    float sideLength;
};

#endif /* Tetrahedron_h */
