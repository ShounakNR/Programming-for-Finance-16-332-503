//
//  main 2.cpp
//  Stars and Stripes
//  Inclass assignment 2 question 2
//  Programming for finance 16:332:503
//  Created by Shounak Rangwala on 9/14/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int numberOfSpaces;
    
    
    do{
    cout << "enter odd number of spaces"<<endl;
    cin >> numberOfSpaces;
    }while(numberOfSpaces%2==0 || numberOfSpaces<0);
    
    int totalRows = numberOfSpaces+2;

    for(int i=0;i<totalRows;i++){
        for (int j=0;j< totalRows;j++){
            if (i+j == (numberOfSpaces+1)/2 || i-j==(numberOfSpaces+1)/2 || j-i ==(numberOfSpaces+1)/2 || j+i == (totalRows-1)+(numberOfSpaces+1)/2){
                cout <<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
