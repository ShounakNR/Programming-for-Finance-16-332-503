//Programming for finance 16:332:503
// Inclass 6
//Shounak Rangwala net:snr85
#include <iostream>

#include "point.h"
#include "threedimensionalpoint.h"

using namespace std;

int main(){
	ThreeDimensionalPoint point1(8,7,4);
	ThreeDimensionalPoint point2(-6,-7,-6);
	point1.addPoints(point2);
	cout<<"\nThe value of the x value is: "<< point1.getx();
	cout<<"\nThe value of the y value is: "<< point1.gety();
	cout<<"\nThe value of the z value is: "<< point1.getz();
	cout<<"\n";
}
