//
//  Booklist_template.h
//  Homework 11
//  Programming for finance 
//  Created by Shounak Rangwala on 11/20/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef Booklist_template_h
#define Booklist_template_h
#include <string.h>
#include <iostream>
using namespace std;
template <class T>
class BookList{
  
public:
    BookList();
    T inputElement ();
    int inputPosition();
    void insertAtEnd( T );
    void printList();
    void insertAtPos (T , int );
    void selectionSort();
    void bubbleSort ();
    int linearSearch(T);
    int binarySearch(int , T );
    void deleteFromPosition (int);
    void deleteFromLabel ();
    T *arr;
    
    bool isSorted ();
    
private:
    bool checkIfFull (int );
    bool checkIfEmpty(int );
    void swap (T *, T *);
    int capacity;
    
};

template <class T>
BookList <T>:: BookList() {
    capacity = 0;
}

template <class T>
T BookList<T>::inputElement(){
    T num;
    cout<<"Enter the name:"<<endl;
    cin>>num;
    return num;
}

template <class T>
int BookList<T>::inputPosition(){
    int num;
    cout<<"enter the position"<<endl;
    cin>>num;
    return num;
}

template <class T>
bool BookList<T>::checkIfFull(int number){
    if (number==20){
        return true;
    }
    else return false;
}

template <class T>
bool BookList<T>::checkIfEmpty(int number){
    
    if(number==0){
        return true;
    }
    else return false;

}

template <class T>
void BookList<T>::insertAtEnd(T newElement){
    if(checkIfFull(capacity)){
        cout<<"List is full";
        return;
    }
    *(arr+capacity) = newElement;
    capacity++;
}

template <class T>
void BookList<T>::insertAtPos( T newElement, int position){
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

template <class T>
void BookList<T>:: printList(){
    
    cout<<"Your list is: "<<endl;
    for(int i=0;i<capacity;i++){
        cout<<i+1<<". "<<*(arr+i)<<endl;
    }

}

template <class T>
void BookList<T>::swap(T *a, T *b){
    
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

template <class T>
void BookList<T>::selectionSort(){
    
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


template <class T>
void BookList<T>::bubbleSort(){
    
    for (int i=0; i<capacity-1;i++){
        for(int j =0;j<capacity-i-1 ;j++){
            if(*(arr+j) > *(arr+j+1)){
                swap(arr+j, arr+j+1);
            }
        }
    }

}

template <class T>
bool BookList<T>::isSorted(){
    
    int a;
    cout<<"enter 1 if list is sorted, 0 if not"<<endl;
    cin>>a;
    if(a==0) return false;
    else return true;

}

template <class T>
int BookList<T>::linearSearch(T searchElement){

     for(int i=0;i<capacity;i++){
         if(*(arr+i)== searchElement){
             return i;
         }
    
     }
      return -1;

}

template <class T>
int BookList<T>::binarySearch(int left, T searchElement){
    
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

template <class T>
void BookList<T>::deleteFromPosition(int position){
    
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

template <class T>
void BookList<T>::deleteFromLabel(){
    
    int position = linearSearch(inputElement());
    deleteFromPosition(position+1);

}

#endif /* Booklist_template_h */
