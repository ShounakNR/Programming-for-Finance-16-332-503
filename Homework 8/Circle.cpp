//
//  Circle.cpp
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

#include "Circle.h"

Circle::Circle(int x, int y, float radius):TwoDimensional(x,y){
    setRadius(radius);
}

void Circle::setRadius(float r){
    radius = r;
}

float Circle::getRadius(){
    return radius;
}

float Circle::getArea(){
    return 3.141 * radius*radius;
}

void Circle::print(){
    cout<<"The circle with radius "<<getRadius()<<" that is located at ("<<Shape::getX()<<","<<Shape::getY()<<") has:"<<endl;
    cout<<"Area = "<<getArea()<<endl;;
}
