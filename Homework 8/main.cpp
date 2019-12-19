//
//  main.cpp
//  Homework 8
//
//  Created by Shounak Rangwala on 10/29/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "Circle.h"
#include "Tetrahedron.h"
#include "Sphere.h"
#include "Triangle.h"
using namespace std;

int main(int argc, const char * argv[]) {
    while (true) {
        int x,y,z,choice;
        float radius, side;
        cout << "Please choose a shape or 0 to exit:" << endl;
        cout << "1. Circle" << endl;
        cout << "2. Triangle" << endl;
        cout << "3. Sphere" << endl;
        cout << "4. Regular Tetrahedron " << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        //Selected different class to calculate the result according to users' selection.
        switch (choice) {
        case 1: {
            cout << endl;
            cout << "You have chosen the circle." << endl;
            cout << endl;
            cout << "Please enter the center of the circle (x-coordinate and then y-coordinate):" << endl;
            cin >> x;                //Input x and y coordinate.
            cin >> y;
            cout << endl;
            cout << "Please enter the radius of the circle." << endl;
            cin >> radius;            //Input radius of circle.
            cout << endl;
            Circle c1 (x, y, radius);
            c1.print();
            break;
            }
        case 2: {
            cout << endl;
            cout << "You have chosen the triangle." << endl;
            cout << endl;
            cout << "Please enter the center of the triangle (x-coordinate and then y-coordinate):" << endl;
            cin >> x;                //Input x and y coordinate.
            cin >> y;
            cout << endl;
            cout << "Please enter the length of the triangle." << endl;
            cin >> side;            //Input length and width of triangle.
            
            cout << endl;
            Triangle T1(x, y, side);
            T1.print();
            break;
            }
        case 3: {
            cout << endl;
            cout << "You have chosen the sphere." << endl;
            cout << endl;
            cout << "Please enter the radius of the sphere." << endl;
            cin >> radius;        //Input radius of sphere.
            cout << endl;
            cout << "Please enter the center of the sphere (x-coordinate, y-coordinate, then z-coordinate):" << endl;
            cin >> x;            //Input x, y and z coordinate.
            cin >> y;
            cin >> z;
            cout << endl;
            Sphere S1(x, y, z, radius);
            S1.print();
            break;
            }
        case 4: {
            cout << endl;
            cout << "You have chosen the regular tetrahedron." << endl;
            cout << endl;
            cout << "Please enter the edge length of the regular tetrahedron." << endl;
            cin >> side;    //Input length of side of tetrahedron.
            cout << endl;
            cout << "Please enter the center of the regular tetrahedron (x-coordinate, y-coordinate, then z-coordinate):" << endl;
            cin >> x;            //Input x, y and z coordinate.
            cin >> y;
            cin >> z;
            cout << endl;
            Tetrahedron TE1(x, y, z, side);
            TE1.print();
            break;
            }
        case 0: {
            cout<<"Quitting program"<<endl;
            return 0;    //Stop and exit the program.
            break;
            }
        }
    }
}
