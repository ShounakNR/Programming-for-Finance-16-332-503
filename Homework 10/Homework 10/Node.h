//
//  Node.h
//  Homework 10
//
//  Created by Shounak Rangwala on 11/9/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include <string>
#include "dataClass.h"

class Node {

public:
    Node (Data);
    int getNumber ();
    string getName();
    void setptr(Node*);
    Node* getptr();
protected:
    Data D1;
    Node *nxtptr;
    
};

#endif /* Node_h */
