//
//  Sphere.h
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef Sphere_h
#define Sphere_h

#include "ThreeDimensional.h"

class Sphere : public ThreeDimensional{
public:
    Sphere(int=0,int=0,int=0,float=0);
    void setRadius(float);
    float getRadius ();
    float getSurfaceArea();
    float getVolume();
    void print();
protected:
    float radius;
};

#endif /* Sphere_h */
