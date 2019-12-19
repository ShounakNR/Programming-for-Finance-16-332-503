//
//  Triangle.h
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h

#include "TwoDimensional.h"

class Triangle: public TwoDimensional {
public:
    Triangle(int=0,int=0,float=0);
    void setSide(float);
    float getSide ();
    float getArea ();
    void print();
protected:
    float side;
};

#endif /* Triangle_h */
