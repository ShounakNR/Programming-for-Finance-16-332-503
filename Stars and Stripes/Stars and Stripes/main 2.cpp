//
//  main.cpp
//  Stars and Stripes 1
//  Inclass Assignment 2 Question 1.
//  Created by Shounak Rangwala on 9/14/19.
//  Programming for Finance 16:332:503
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int linesNumber;
    cout << "Enter number of lines"<< endl;
    cin >> linesNumber;
    for (int i=0; i<=linesNumber; i++){
        for (int j = 0; j < i;j++){
            cout <<"*";
        }
        cout<<endl;
    }
    return 0;
}
