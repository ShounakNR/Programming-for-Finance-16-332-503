//
//  LinkedList.h
//  Homework 10
//
//  Created by Shounak Rangwala on 11/9/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"
#include <iostream>
#include <string>
#include <new>
using namespace std;

class List {
    
public:
    List();
//    ~List();
    void addToStart(Node *);
    void addToEnd(Node *);
    void printList();
    int size();
    void removeFromStart ();
    void removeFromEnd ();
    void removeNodeFromNumber(int);
    void removeNodeFromName(string);
    Node* getHead();
    Node* getTail();
    
    
private:
    Node * head;
    Node * tail;
    int listSize;
};
#endif /* LinkedList_h */
