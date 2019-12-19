//Shounak Rangwala
// netid: snr85;
//Programming for finance 16:332:503
//inclass 6

#include <iostream>
#include "threedimensionalpoint.h"

using namespace std;
ThreeDimensionalPoint::ThreeDimensionalPoint(){
	setx(0);
	sety(0);
	setz(0);
}

ThreeDimensionalPoint::ThreeDimensionalPoint(int xin, int yin, int zin): Point(){
    
	//please implement this constructor to set the x, y and z values to the input parameter values
    Point::setx(xin);
    Point::sety(yin);
    setz(zin);
}
int ThreeDimensionalPoint::getz(){
	//please implement this function to get the z value
    return z;
}
void ThreeDimensionalPoint::setz(int zin){
	//please implement this function to set z value
    z = zin;
}

void ThreeDimensionalPoint::addPoints(ThreeDimensionalPoint pointin){
	//please implement this function to add the x,y and z values of point1 to values of the calling instance of the object
    Point::setx(Point::getx()+pointin.getx());
    Point::sety(Point::gety()+pointin.gety());
    setz(getz()+pointin.getz());
}
