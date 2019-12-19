//
//  Tetrahedron.cpp
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(int x, int y,int z,float side):ThreeDimensional(x,y,z){
    setSide(side);
}

void Tetrahedron::setSide(float s){
    sideLength=s;
}

float Tetrahedron::getSide(){
    return sideLength;
}

float Tetrahedron::getVolume(){
    return sideLength*sideLength*sideLength/6/sqrt(2);
}

float Tetrahedron::getSurfaceArea(){
    return sqrt(3)*sideLength*sideLength;
}

void Tetrahedron::print(){
    cout<<"The tetrahedron with length "<<getSide()<<" that is located at ("<<Shape::getX()<<","<<Shape::getY()<<","<<ThreeDimensional::getZ()<<") has:"<<endl;
    cout<<"Surface Area = "<<getSurfaceArea()<<endl;
    cout<<"Volume = "<<getVolume()<<endl;
}
