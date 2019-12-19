//
//  main.cpp
//  Homework 4 ISBN
//  Programming for finance 16:332:503.
//  Created by Shounak Rangwala on 9/30/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
using namespace std;

int inputElement (){
    int num;
    cout<<"Enter the ISBN number"<<endl;
    cin>>num;
    return num;
}

int inputPosition(){
    int num;
    cout<<"enter the position"<<endl;
    cin>>num;
    return num;
}

bool checkIfFull (int number){
    if (number==20){
        return true;
    }
    else return false;
}

bool checkIfEmpty(int number){
    if(number==0){
        return true;
    }
    else return false;
}

void insertAtEnd(int *arr, int capacity, int newElement){
    if(checkIfFull(capacity)){
        cout<<"List is full";
        return;
    }
    *(arr+capacity) = newElement;
}

void printList(int *arr, int capacity){
    cout<<"Your list is: "<<endl;
    for(int i=0;i<capacity;i++){
        cout<<i+1<<". "<<*(arr+i)<<endl;
    }
}

void insertAtPos (int *arr, int capacity, int newElement, int position){
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
}

void swap (int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort( int *arr, int capacity){
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

void bubbleSort (int *arr, int capacity){
    for (int i=0; i<capacity-1;i++){
        for(int j =0;j<capacity-i-1 ;j++){
            if(*(arr+j) > *(arr+j+1)){
                swap(arr+j, arr+j+1);
            }
        }
    }
}

int linearSearch( int *arr, int capacity, int searchElement){
    for(int i=0;i<capacity;i++){
        if(*(arr+i)== searchElement){
            return i;
        }
   
    }
     return -1;
}

int binarySearch(int *arr, int left,int capacity, int searchElement){
    int r =capacity-1;
    int l=left;
    if (1){
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == searchElement){
                return mid;
            }
                
            if (arr[mid] > searchElement){
                return binarySearch(arr, l, mid - 1, searchElement);
            }
                  
            return binarySearch(arr, mid + 1, r, searchElement);
          }
          
    }
    return -1;
}

bool isSorted (){
    int a;
    cout<<"enter 1 if list is sorted, 0 if not"<<endl;
    cin>>a;
    if(a==1) return true;
    return false;
}

void deleteFromPosition (int *arr, int capacity, int position){
    if(checkIfEmpty(capacity)){
        cout<<"list is empty "<<endl;
        return;
    }
    if(position>= capacity){
        cout<<"no element there"<<endl;
        return;
    }
    for(int i=position;i<capacity;i++){
        *(arr+i-1)= *(arr+i);
        
    }
}

void deleteFromISBN (int *arr, int capacity){
    int position = linearSearch(arr, capacity, inputElement());
    deleteFromPosition(arr, capacity, position+1);
}

int main(int argc, const char * argv[]) {
    int bookList [20] = {0};
    int currentCapacity = 0;
    while (true) {
        cout<<"Welcome to the booklist program"<<endl;
        cout<<"What would you like to do"<<endl;
        cout<<"1. Add an element to end of list"<<endl;
        cout<<"2. Add an element at a location"<<endl;
        cout<<"3. find an element by ISBN number (linear search)"<<endl;
        cout<<"4. find an element by ISBN number (binary search)"<<endl;
        cout<<"5. delete an element at position"<<endl;
        cout<<"6. delete an element by ISBN number"<<endl;
        cout<<"7. sort the list (using selection sort)"<<endl;
        cout<<"8. sort the list (using bubble sort)"<<endl;
        cout<<"9. print the list"<<endl;
        cout<<"0. exit"<<endl;

        int choice,location;
        cin>>choice;
        switch (choice) {
            case 1:
                insertAtEnd(bookList,currentCapacity,inputElement());
                currentCapacity ++;
                printList(bookList, currentCapacity);
                break;
            case 2:
                insertAtPos(bookList,currentCapacity,inputElement(),inputPosition());
                currentCapacity++;
                printList(bookList, currentCapacity);
                break;
            case 3:
                location = linearSearch(bookList, currentCapacity, inputElement());
                if(location ==-1){
                    cout<<"element is not in list"<<endl;
                }
                cout<<"The element is present at "<<location +1<<endl;
                break;
            case 4:
                if(!isSorted()){
                    bubbleSort(bookList, currentCapacity);
                }
                location = binarySearch(bookList, 0, currentCapacity, inputElement());
                if(location == -1){
                    cout<<"element not in list"<<endl;
                }
                cout<<"The element is present at "<<location+1<<endl;
                break;
            case 5:
                deleteFromPosition(bookList, currentCapacity, inputPosition());
                currentCapacity--;
                printList(bookList, currentCapacity);
                break;
            case 6:
                deleteFromISBN(bookList,currentCapacity);
                currentCapacity--;
                printList(bookList, currentCapacity);
                break;
            case 7:
                selectionSort(bookList, currentCapacity);
                printList(bookList, currentCapacity);
                break;
            case 8:
                bubbleSort(bookList, currentCapacity);
                printList(bookList, currentCapacity);
                break;
            case 9:
                printList(bookList, currentCapacity);
                break;
            case 0:
                return 0;

        }
   }
    return 0;
}

