//
//  DoubleList.h
//  Final Project
//
//  Created by Shounak Rangwala on 11/24/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h
#include <string>
#include "StockNode.h"
#include <iostream>
using namespace std;

class DoubleList {
    friend class StockAccount;
public:
    DoubleList();
    void addToEnd(StockNode*);
    int size();
    
    void bubblesortList();
    void selectionsortList();
    void printList();
    float calcTotal();
    StockNode* getHead();
    StockNode* getTail();
    void copyToPortfolio();
    void removeNode (StockNode*);
private:
    void swap(StockNode*,StockNode*);
    void removeFromStart (StockNode*);
    void removeFromEnd (StockNode*);
    StockNode* head;
    StockNode* tail;
    int listsize;
};

#endif /* DoubleList_h */
