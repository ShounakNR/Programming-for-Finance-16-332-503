//
//  StockNode.cpp
//  Final Project
//
//  Created by Shounak Rangwala on 11/24/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "StockNode.h"
#include <string>
using namespace std;

StockNode::StockNode(){
    NumberOfStocks = 0;
    Value = 0;
    setNextPtr(NULL);
    Name = "empty";
    Total = 0;
}

void StockNode::setStockName(string name){
    Name = name;
}

string StockNode::getStockName(){
    return Name;
}

void StockNode::setQuantity(int number){
    NumberOfStocks += number;
}

int StockNode::getQuantity(){
    return NumberOfStocks;
}

void StockNode::setNextPtr(StockNode * ptr){
    next = ptr;
}

void StockNode::setPrevPtr(StockNode *ptr){
    prev = ptr;
}

void StockNode::setValue(float a){
    Value = a;
}

void StockNode::setTotal(float a){
    Total = a;
}

StockNode* StockNode::getNextPtr(){
    return next;
}

StockNode* StockNode:: getPrevPtr(){
    return prev;
}

float StockNode::getValue(){
    return Value;
}

float StockNode::getTot(){
    return Total;
}
