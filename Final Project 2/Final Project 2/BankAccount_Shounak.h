//
//  BankAccount_Shounak.h
//  Final Project
//
//  Created by Shounak Rangwala on 11/14/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef BankAccount_Shounak_h
#define BankAccount_Shounak_h
#include "Account_Shounak.h"

class BankAccount: public Account{
public:
    BankAccount();
    void setBalance(float);
    float getBalance();
    void addMoney(float);
    int removeMoney(float);
    void printHistory();
    void updateFile();
protected:
    float money;
    
};
#endif /* BankAccount_Shounak_h */
