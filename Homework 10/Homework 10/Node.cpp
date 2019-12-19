//
//  Node.cpp
//  Homework 10
//
//  Created by Shounak Rangwala on 11/9/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "Node.h"
using namespace std;

Node:: Node(Data item){
    D1 = item;
    nxtptr = NULL;
}

int Node::getNumber(){
    return D1.getItemNumber();
}

string Node::getName(){
    return D1.getName();
}

void Node:: setptr(Node* ptr){
    nxtptr = ptr;
}

Node* Node:: getptr(){
    return nxtptr;
}
