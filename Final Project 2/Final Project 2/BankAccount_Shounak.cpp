//
//  BankAccount_Shounak.cpp
//  Final Project
//
//  Created by Shounak Rangwala on 11/14/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <time.h>
#include "BankAccount_Shounak.h"
#include <iomanip>
using namespace std;

BankAccount::BankAccount(){
    ifstream startingMoney ("bankBalance.txt");
    if(!startingMoney.is_open()){
        ofstream setMoney;
        setMoney.open("bankBalance.txt");
        setBalance(10000);
        setMoney<< getBalance();
        setMoney.close();
    }
    else{
        float inputCash;
        ifstream getLatestBalance ("bankBalance.txt");
        getLatestBalance >> inputCash;
        setBalance(inputCash);
        getLatestBalance.close();
    }
    ifstream hist ("bank_history_transaction.txt");
    if(!hist.is_open()){
        ofstream setMoney;
        setMoney.open("bank_history_transaction.txt");
        setMoney <<left<<  setw(15) << "Event" << left<<setw(15) << "Amount" <<left<<setw(15) << "Date" << left<<setw(15) << "Balance" << endl;
        setMoney.close();
    }
    
    ifstream portfolioValue ("portfolioValue.txt");
    if(!portfolioValue.is_open()){
        ofstream create;
        create.open("portfolioValue.txt");
        time_t seconds;
        seconds = time(NULL);
        tm * timeinfo;
        timeinfo = localtime(&seconds);
        create <<  setw(10) << getBalance() <<"\t"<< setw(10) << seconds << "\n";
        create.close();
    }
    
}

void BankAccount::setBalance(float a){
    money = a;
}

float BankAccount::getBalance(){
    return money;
}

void BankAccount::addMoney(float deposit){
    money += deposit;
    ofstream add("bankBalance.txt");
    add << money<<endl;
    add.close();
    
    time_t seconds;
    seconds = time(NULL);
    tm * timeinfo;
    timeinfo = localtime(&seconds);
    
    ofstream hist;
    hist.open("bank_history_transaction.txt", ios::app);
    hist <<left<<setw(15) << "Deposit" <<left << "$" <<left<<setw(14)<<deposit << left<<setw(2) << timeinfo->tm_mon+1<<left<<"/"<<left<<setw(2)<<timeinfo->tm_mday<<left<<"/"<<left<<setw(9)<<timeinfo->tm_year+1900 <<left<<setw(15) << money << endl;
    
    hist.close();
    
    ofstream value;
    value.open("portfolioValue.txt",ios::app);
    value <<  setw(10) << getBalance() <<"\t"<< setw(10) << seconds << "\n";
    value.close();
    
}

int BankAccount::removeMoney(float withdrawal){
    
    money -= withdrawal;
    if(money<0){
        return -1;
    }
    ofstream add("bankBalance.txt");
    add << money<<endl;
    add.close();
    
    time_t seconds;
    seconds = time(NULL);
    tm * timeinfo;
    timeinfo = localtime(&seconds);
    
    ofstream hist;
    hist.open("bank_history_transaction.txt", ios::app);
     hist <<left<<setw(15) << "Withdrawal" <<left << "$" <<left<<setw(14)<<withdrawal << left<<setw(2) << timeinfo->tm_mon+1<<left<<"/"<<left<<setw(2)<<timeinfo->tm_mday<<left<<"/"<<left<<setw(9)<<timeinfo->tm_year+1900 <<left<<setw(15) << money << endl;
      
    hist.close();
    
    ofstream value;
    value.open("portfolioValue.txt",ios::app);
    value <<  setw(10) << getBalance() <<"\t"<< setw(10) << seconds << "\n";
    value.close();
    return 1;
}

void BankAccount::printHistory(){
    ifstream read("bank_history_transaction.txt");
    char line[100];
    while (!read.eof()) {
        read.getline(line, 100);
        cout << line << endl;
    }
    read.close();
    
}


