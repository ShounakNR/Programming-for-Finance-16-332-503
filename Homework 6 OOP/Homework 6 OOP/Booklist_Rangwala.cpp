//
//  Booklist_lastName.cpp
//  Homework 6 OOP
//  Programming for finance 16:332:503
//  Created by Shounak Rangwala on 10/12/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
using  namespace std;

#include "Booklist_Rangwala.h"

BookList::BookList(){
    capacity=0;
}

int BookList::inputElement(){
    int num;
    cout<<"Enter the ISBN number"<<endl;
    cin>>num;
    return num;
}

int BookList::inputPosition(){
    int num;
    cout<<"enter the position"<<endl;
    cin>>num;
    return num;
}

bool BookList::checkIfFull(int number){
    if (number==20){
        return true;
    }
    else return false;
}

bool BookList::checkIfEmpty(int number){
    
    if(number==0){
        return true;
    }
    else return false;

}

void BookList::insertAtEnd(int newElement){
    if(checkIfFull(capacity)){
        cout<<"List is full";
        return;
    }
    *(arr+capacity) = newElement;
    capacity++;
}

void BookList::insertAtPos( int newElement, int position){
    if(checkIfFull(capacity)){
        cout<<"List is full"<<endl;
        return;
    }
    else if (checkIfEmpty(capacity)){
        position = 0;
    }
    for(int i= capacity; i>position-1;i-- ){
        arr[i] = arr[i-1];
    }
    arr[position-1] = newElement;
    capacity++;
}

void BookList:: printList(){
    
    cout<<"Your list is: "<<endl;
    for(int i=0;i<capacity;i++){
        cout<<i+1<<". "<<*(arr+i)<<endl;
    }

}

void BookList::selectionSort(){
    
    int temp;
    for (int i=0;i<capacity-1;i++){
        temp = i;
        for(int j=i+1;j<capacity;j++){
            if(*(arr+j) < *(arr+temp)){
                temp=j;
            }
            swap(arr+temp, arr+i);
        }
    }

}

void BookList::swap(int *a, int *b){
    
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void BookList::bubbleSort(){
    
    for (int i=0; i<capacity-1;i++){
        for(int j =0;j<capacity-i-1 ;j++){
            if(*(arr+j) > *(arr+j+1)){
                swap(arr+j, arr+j+1);
            }
        }
    }

}

bool BookList::isSorted(){
    
    int a;
    cout<<"enter 1 if list is sorted, 0 if not"<<endl;
    cin>>a;
    if(a==1) return true;
    return false;

}

int BookList::linearSearch(int searchElement){

     for(int i=0;i<capacity;i++){
         if(*(arr+i)== searchElement){
             return i;
         }
    
     }
      return -1;

}

int BookList::binarySearch(int left, int searchElement){
    
    int r =capacity-1;
    int l=left;
    if (1){
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == searchElement){
                return mid;
            }
                
            if (arr[mid] > searchElement){
                return binarySearch(l, searchElement);
            }
                  
            return binarySearch(mid + 1, searchElement);
          }
          
    }
    return -1;

}

void BookList::deleteFromPosition(int position){
    
    if(checkIfEmpty(capacity)){
        cout<<"list is empty "<<endl;
        return;
    }
    if(position> capacity){
        cout<<"no element there"<<endl;
        return;
    }
    for(int i=position;i<capacity;i++){
        *(arr+i-1)= *(arr+i);
        
    }
    capacity--;

}

void BookList::deleteFromISBN(){
    
    int position = linearSearch(inputElement());
    deleteFromPosition(position+1);

}

