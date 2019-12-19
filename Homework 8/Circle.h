//
//  Circle.h
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include "TwoDimensional.h"

class Circle : public TwoDimensional {
public:
    Circle (int=0,int=0,float=0);
    void setRadius (float);
    float getRadius ();
    float getArea ();
    void print();
protected:
    float radius;
};

#endif /* Circle_h */
