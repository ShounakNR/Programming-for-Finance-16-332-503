//
//  Shape.cpp
//  Homework 8
//
//  Created by Shounak Rangwala on 10/29/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "Shape.h"
using namespace std;

/*Constructor.*/
Shape::Shape(int xValue, int yValue) {
    setX(xValue);
    setY(yValue);
}

void Shape::setX(int a){
    x=a;
}
void Shape::setY(int b){
    y=b;
}

int Shape::getX(){
    return x;
}
int Shape::getY(){
    return y;
}


