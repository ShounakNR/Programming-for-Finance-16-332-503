//
//  HW-5 part 2.cpp
//  Homework 5
//  programming for finance 16:332:503.
//  Created by Shounak Rangwala on 10/9/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>

using namespace std;

bool has_solution(int *arr, int startingPoint){
    int index=0;
    do{
        index++;
    }while(*(arr+index)!=0);
    index++;//size of the input array
    if(startingPoint<0 || startingPoint>index){
        return false;
    }
    else if(*(startingPoint+arr)==-1){
        return false;
    }
    else if(*(startingPoint+arr)==0){
        return true;
    }
    else{
        int nextStart1 = startingPoint+*(arr+startingPoint);
        int nextStart2 = startingPoint-*(arr+startingPoint);
        *(arr+startingPoint) = -1;
        return has_solution(arr, nextStart1)|| has_solution(arr, nextStart2);
    }
    
   
}

int  main (){
    int array[100];
    int input, i=0;
    cout<<"Enter the elements of the array: "<<endl;
    do{
        cin>>input;
        if(input<0){
            cout<<"only positive numbers can be entered"<<endl;
            continue;
        }
        array[i] = input;
        i++;
    }while (input!=0);
    int array2[i];
    for(int j=0;j<i;j++){
//        cout<<array[j]<<"\t";
        array2[j]=array[j];
    }
    if(has_solution(array2,0)){
        cout<<"Has solution"<<endl;
    }
    else{
        cout<<"No solution"<<endl;
    }
}
