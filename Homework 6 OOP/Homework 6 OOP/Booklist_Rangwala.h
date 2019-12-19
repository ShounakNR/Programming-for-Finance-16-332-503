//
//  Booklist_lastName.h
//  Homework 6 OOP
//  Programming for finance 16:332:503
//  Created by Shounak Rangwala on 10/12/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef Booklist_lastName_h
#define Booklist_lastName_h
class BookList{
  
public:
    BookList();
    int inputElement ();
    int inputPosition();
    void insertAtEnd( int );
    void printList();
    void insertAtPos (int , int );
    void selectionSort();
    void bubbleSort ();
    int linearSearch(int);
    int binarySearch(int , int );
    void deleteFromPosition (int);
    void deleteFromISBN ();
    int *arr;
    
    bool isSorted ();
    
private:
    bool checkIfFull (int );
    bool checkIfEmpty(int );
    void swap (int *, int *);
    int capacity;
    
};

#endif /* Booklist_lastName_h */
