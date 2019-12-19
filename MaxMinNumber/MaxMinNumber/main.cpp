//
//  main.cpp
//  MaxMinNumber
//  Course: 16:332:503 Programming for finance
//  Created by Shounak Rangwala on 9/7/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[5],minimum,maximum;
    cout << "Please enter the five numbers"<<endl;
    for (int i=0; i<5 ;i++) {
        cin>>arr[i];
    }
//    for (int i=0;i<5;i++){
//        cout << arr[i] <<"\t";
//    }
    minimum=maximum=arr[0];
    for (int i=0;i<5;i++){
        if(arr[i]>maximum){
            maximum = arr[i];
        }
        if(arr[i]<minimum){
            minimum = arr[i];
        }
    }
    cout << "Maximum is: " << maximum << "\t" << "minimum is: "<< minimum<<endl;
    return 0;
}
