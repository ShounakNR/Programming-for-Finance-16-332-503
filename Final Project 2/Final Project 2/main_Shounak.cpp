//
//  main.cpp
//  Final Project
//
//  Created by Shounak Rangwala on 11/13/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <fstream>
#include "StockPortfolio.h"
#include "BankAccount_Shounak.h"
#include "DoubleList.h"
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
void bankAcc();
void stockAcc();

int main() {
    
    int choice;
       
    while(true){
        cout<<"Welcome to Account Management System."<<endl;
        cout<<"Please select an account to access:"<<endl;
        cout<<"1) Stock Portfolio Account"<<endl;
        cout<<"2) Bank Account"<<endl;
        cout<<"3)Exit"<<endl;
        cout << "Option: ";
        cin >> choice;
        cout << endl;
        if (choice>3 || choice<1) {
            continue;
        }
        else {
            break;
        }
    }
        
        while (true) {
            switch (choice) {
            case 1: {
                stockAcc();
                return 0;
            }
            case 2: {
                bankAcc();
                return 0;
            }
            case 3: {
                return 0;
            }

            }
        }
//    ifstream open ("portfolioValue.txt");
//    vector<int> a;
//    vector<double>b;
//    int count=0;
//    while(!open.eof()){
//        int x;
//        double y;
//        if(count%2==0){
//            open>>x;
//            a.push_back(x);
//        }
//        else{
//            open>>y;
//            b.push_back(y);
//        }
//        count++;
//    }
//    for(int i=0;i<b.size();i++){
//        cout<<b[i]<<endl;
//    }
        return 0;
}
void bankAcc() {
    int choice;
    BankAccount *bk = new BankAccount();
    while (true) {
        cout << "Please select an option" << endl;
        cout << "1. View account balance." << endl;
        cout << "2. Deposit money." << endl;
        cout << "3. Withdraw money." << endl;
        cout << "4. Print out history." << endl;
        cout << "5. Return to previous menu" << endl;
        cout << "Option: ";
        cin >> choice;
        if (choice > 5 || choice < 1) {
            cout << "The option number is wrong. Please enter a option between 1 and 5." << endl;
            cout << "Option: ";
            cin >> choice;
        }
        cout << endl;
        switch (choice) {
        case 1: {
            float cash = bk->getBalance();
            cout << setiosflags(ios::fixed) << setprecision(2);
            cout << "1. You have $" << cash << " in your bank account" << endl;
            cout << endl;
            break;
        }
        case 2: {
            float depositAmount;
            cout << "Please select the amount you wish to deposit: $" ;
            cin >> depositAmount;
            bk->addMoney(depositAmount);
            break;
        }
        case 3: {
            float withdrawAmount;
            cout << "Please select the amount you wish to withdraw: $";
            cin >> withdrawAmount;
            int tag = bk->removeMoney(withdrawAmount);
            if (tag == -1) {
                cout << "Fail: The cash balance is not enough." << endl;
                cout << endl;
            }
            else {
                cout << "Withdraw successfully!" << endl;
                cout << endl;
            }
            break;
        }
        case 4: {
            bk->printHistory();
            cout << endl;
            break;
        }
        case 5: {
            main();
            return;
        }
            default: return;
        }
    }
}

void stockAcc() {
    int choice;
    //Create a stockAccount.
    StockPortfolio *sa = new StockPortfolio();

    while (true) {

        cout << "Please select an option:" << endl;
        cout << "1. Display the price of a stock symbol." << endl;
        cout << "2. Display the current portfolio." << endl;
        cout << "3. Buy shares." << endl;
        cout << "4. Sell shares." << endl;
        cout << "5. View a graph for the portfolio value." << endl;
        cout << "6. View transaction history." << endl;
        cout << "7. Return to previous menu." << endl;

        cout << "Option: ";
        cin >> choice;
        if (choice > 7 || choice < 1) {
            cout << "The option number is wrong. Please enter a option between 1 and 7." << endl;
            cout << "Option: ";
            cin >> choice;
        }
        cout << endl;
        switch (choice) {
        case 1: {//get stock price.
            string companySymbol;
            cout << "Please enter the stock symbol: ";
            cin >> companySymbol;
            string arr[2]={"Result_1.txt","Result_2.txt"};
            srand(unsigned(time(NULL)));
            int v = rand()%2;
            string fileName = arr[v];
            float price = sa->DisplayPrice(fileName, companySymbol);
            if (price != -1) {
                cout << "Company symbol price per share" << endl;
                cout << setiosflags(ios::fixed) << setprecision(2);
                cout << companySymbol << " $" << price << endl;
            }
            cout << endl;
            break;
        }
        case 2: {//print portfolio
            sa->DisplayPortfolio();
            break;
        }
        case 3: {//buy
            string companySymbol;
            cout << "Please enter the stock symbol you wish to purchase: ";
            cin >> companySymbol;
            int shares;
            cout << "Please enter the number of shares: ";
            cin >> shares;
            float price;
            cout << "Please enter the maximum amount you are willing to pay per share: ";
            cin >> price;

            int a = sa->Buy(companySymbol, shares, price);
            if(a==1){
                cout<<"Successfully bought"<<endl;
            }

            cout << endl;
            break;
        }
        case 4: {//sell
            string companySymbol;
            cout << "Please enter the stock symbol you wish to sell: ";
            cin >> companySymbol;
            int shares;
            cout << "Please enter the number of shares: ";
            cin >> shares;
            double price;
            cout << "Please enter the maximum amount you are willing to pay per share: ";
            cin >> price;

            int b = sa->Sell(companySymbol, shares, price);
            if(b==1){
                cout<<"Successfully sold"<<endl;
            }

            cout << endl;
            break;
        }
        case 5: {//graph with MATLAB.
            sa->viewGraph();
            break;
        }
        case 6: {//print transaction history.
            sa->viewHistory();
            cout << endl;
            break;
        }
        case 7: {//return to main menu.
            main();
            return;
        }
            default: return;
        }
    }
    return;
}
