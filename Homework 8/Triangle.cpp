//
//  Triangle.cpp
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
#include "Triangle.h"

Triangle::Triangle(int x,int y,float s):TwoDimensional(x,y){
    setSide(s);
}

void Triangle::setSide(float s){
    side=s;
}

float Triangle::getSide(){
    return side;
}

float Triangle::getArea(){
    return sqrt(3)*side*side/4;
}

void Triangle::print(){
    cout<<"The triangle with length "<<getSide()<<" that is located at ("<<Shape::getX()<<","<<Shape::getY()<<") has:"<<endl;
    cout<<"Area = "<<getArea()<<endl;
}
