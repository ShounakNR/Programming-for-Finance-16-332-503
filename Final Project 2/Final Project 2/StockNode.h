//
//  StockNode.h
//  Final Project
//
//  Created by Shounak Rangwala on 11/24/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef StockNode_h
#define StockNode_h
#include <string>
using namespace std;
class StockNode{
public:
    friend class DoubleList;
    StockNode();
    string getStockName();
    void setStockName(string);
    int getQuantity();
    void setQuantity(int);
    void setValue(float);
    void setPrevPtr(StockNode*);
    void setNextPtr(StockNode*);
    StockNode* getNextPtr();
    StockNode* getPrevPtr();
    
    void setTotal(float);
    float getValue();
    float getTot();
private:
    int NumberOfStocks;
    float Value;
    string Name;
    StockNode *prev;
    StockNode *next;
    float Total;

};

#endif /* StockNode_h */
