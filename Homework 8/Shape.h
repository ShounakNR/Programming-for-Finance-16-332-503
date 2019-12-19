//
//  Shape.h
//  Homework 8
//
//  Created by Shounak Rangwala on 10/29/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef Shape_h
#define Shape_h
class Shape {
public:
    Shape(int =0,int=0);
    void setX(int);
    void setY(int);

    int getX ();
    int getY ();

protected:
    int x;
    int y;
    int z;
};


#endif /* Shape_h */
