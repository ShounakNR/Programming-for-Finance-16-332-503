//
//  Sphere.cpp
//  Homework 8
//
//  Created by Shounak Rangwala on 10/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Sphere.h"

Sphere::Sphere(int x,int y,int z,float radius):ThreeDimensional(x,y,z){
    setRadius(radius);
}
void Sphere::setRadius(float r){
    radius = r;
}

float Sphere::getRadius(){
    return radius;
}

float Sphere::getVolume(){
    return 4/3*3.141*radius*radius;
}

float Sphere::getSurfaceArea(){
    return 4* 3.141*radius;
}

void Sphere::print(){
    cout<<"The sphere with radius "<<getRadius()<<" that is located at ("<<Shape::getX()<<","<<Shape::getY()<<","<<ThreeDimensional::getZ()<<") has:"<<endl;
    cout<<"Surface Area = "<<getSurfaceArea()<<endl;
    cout<<"Volume = "<<getVolume()<<endl;
}

