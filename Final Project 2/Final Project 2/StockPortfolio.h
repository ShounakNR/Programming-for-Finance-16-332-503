//
//  StockPortfolio.h
//  Final Project
//
//  Created by Shounak Rangwala on 11/24/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef StockPortfolio_h
#define StockPortfolio_h
#include <string>
#include <iostream>
#include "Account_Shounak.h"
#include "DoubleList.h"
using namespace std;

class StockPortfolio: public Account {
public:
    StockPortfolio();
    void setBalance(float);
    float getBalance();
    float DisplayPrice (string,string);
    void DisplayPortfolio();
    int Buy(string,int,float);
    int Sell(string,int,float);
    void viewHistory();
    void viewGraph();
    void updatePortfolio();
    void print();
    
    
    
private:
    string StockName;
    int NumberofStocks;
    float TotalValue;
    float Balance;
    DoubleList * List;
};

#endif /* StockPortfolio_h */
