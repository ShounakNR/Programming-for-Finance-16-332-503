//
//  StockPortfolio_Shounak.cpp
//  Final Project
//
//  Created by Shounak Rangwala on 11/25/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StockPortfolio.h"
#include <string>
#include <time.h>
#include <fstream>
#include "BankAccount_Shounak.h"
#include <vector>
#include <iomanip>
//#include <yvals.h>
//#include <engine.h>
//#include <vector>
//#include "mex.h"
//#if(_MSC_VER>=1600)
//#define _STDC_utf_16__
//#endif
//#pragma comment(lib,"libmx.lib")
//#pragma comment(lib,"libmex.lib")
//#pragma comment(lib,"libeng.lib")

using namespace std;

StockPortfolio::StockPortfolio(){
    TotalValue =0;
    
//    Open bank_history_transaction.txt if not created create it
    ifstream passbook ("bank_history_transaction.txt");
    if(!passbook.is_open()){
        ofstream setMoney;
        setMoney.open("bank_history_transaction.txt");
        setMoney <<left<<  setw(15) << "Event" << left<<setw(15) << "Amount" <<left<<setw(15) << "Date" << left<<setw(15) << "Balance" << endl;
        setMoney.close();
    }
    
//    open bankBalance.txt, if not created create it. read the value into the Balance
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
    
//    Open stock_history_transaction.txt , if not created, create it
    ifstream Hist ("stock_history_transaction.txt");
    if(!Hist.is_open()){
        ofstream setMoney;
        setMoney.open("stock_history_transaction.txt");
        setMoney << left<< setw(15)<< "Event" << left<< setw(15)<< "Comp Sign" << left<< setw(15) <<  "Number"<< left<< setw(15)<< "Price/Share" << left<< setw(15)<< "Total Value"<< left<< setw(15)<< "Time"<<endl;
        setMoney.close();
    }
    
//    Open stockPortfolio.txt , if that is not created, create it. If created, read the values into the linkedList.
    ifstream portfolioRead("stockPortfolio.txt");
    if (!portfolioRead.is_open()) {
        ofstream file;
        file.open("stockPortfolio.txt");
        file << left << setw(20) << "Comp Symbol" << left << setw(10) << "Number" << left << setw(20) << "PricePerShare" << left << setw(10) << "Total value" << "\n";
        file.close();
        List = new DoubleList();
    }
    else{
//    if the portfolio is created already, read the text into the double linked list
        string a;
        for(int i=0;i<6;i++){
            portfolioRead>>a;
        }
        int counter = 0;
        string name;
        float price=0;
        int shares=0;
        float value=0;
        List = new DoubleList();
        while (!portfolioRead.eof()) {
            if (counter % 4 == 0 && counter > 0) {
                StockNode *newNode = new StockNode();
                newNode->setStockName(name);
                newNode->setQuantity(shares);
                newNode->setValue(price);
                newNode->setTotal(value);
                List->addToEnd(newNode);
                portfolioRead >> name;
            }
            if (counter % 4 == 0 && counter == 0) portfolioRead >> name;
            if (counter % 4 == 1) portfolioRead >> shares;
            if (counter % 4 == 2) portfolioRead >> price;
            if (counter % 4 == 3) portfolioRead >> value;
            counter++;
        }
//        TotalValue = List->calcTotal();
        portfolioRead.close();
    }
    
//   Open portfolioValue.txt to read the portfolioValue. Create it if not created.
    ifstream portfolioValue ("portfolioValue.txt");
    if(!portfolioValue.is_open()){
        ofstream create;
        create.open("portfolioValue.txt");
        time_t seconds;
        seconds = time(NULL);
        tm * timeinfo;
        timeinfo = localtime(&seconds);
        create <<left << Balance <<"\t" << seconds << "\n";
        create.close();
    }
    else{
        portfolioValue>>TotalValue;
        portfolioValue.close();
    }
    
}

void StockPortfolio::setBalance(float a){
    Balance = a;
}

float StockPortfolio::getBalance(){
    return Balance;
}

void StockPortfolio::viewHistory(){
    ifstream read("stock_history_transaction.txt");
    char line[100];
    while (!read.eof()) {
        read.getline(line, 100);
        cout << line << endl;
    }
    read.close();
    
}

float StockPortfolio::DisplayPrice(string filename, string Stock){
    float priceOfStock;
    StockName = Stock;
    ifstream read (filename);
    if(!read.is_open()){
        cout<<"No such file"<<endl;
        return -1;
    }
    else{
        string iter;
        do{
            read>>iter;
        }while(iter!=StockName);
        if(read.eof()){
            cout<<"Company not found"<<endl;
            return -1;
        }
        read>>priceOfStock;
        return priceOfStock;
    }
}

int StockPortfolio::Buy(string name, int Number, float upper){
    string arr[2]={"Result_1.txt","Result_2.txt"};
    srand(time(NULL));
    int v = rand()%2;
    string fileName = arr[v];
    
//    change the values of the total valu of each node
    
    
    float actualPrice = DisplayPrice(arr[v], name);
    if(actualPrice==-1){
        cout<<"wrong symbol"<<endl;
        return -1;
    }
    if(upper<actualPrice || (actualPrice*Number)> Balance){
        cout<<"Fail Out of Budget"<<endl;
        return 2;
    }
    else{
        StockNode* current = List->getHead();
        
         if(List->size()==0){
                    StockNode* N1 = new StockNode();
                    N1->setStockName(name);
                    N1->setQuantity(Number);
                    N1->setValue(actualPrice);
                    N1->setTotal(N1->getValue()*N1->getQuantity());
                    List->addToEnd(N1);
                    float TotalList = List->calcTotal();
                    Balance -= (N1->getQuantity()*N1->getValue());
             TotalValue = TotalList + Balance;
                    
                    ofstream add("bankBalance.txt");
                    add << Balance<<endl;
                    add.close();
                    
                    ofstream file;
                    file.open("stock_history_transaction.txt", ios::app);
                    
                    //calcuate the time.
                    time_t seconds;
                    seconds = time(NULL);
                    tm * timeinfo;
                    timeinfo = localtime(&seconds);
                    
                    file << setiosflags(ios::fixed) << setprecision(2);
                    
             file << std::left << setw(15) << "Buy" << std::left << setw(15) << name << std::left << setw(15) << Number << std::left << setw(1) << "$" << std::left << setw(14) << actualPrice << std::left << setw(1) << "$" << std::left << setw(14) << N1->getTot()<< std::left  <<setw(2)<< timeinfo->tm_hour<<":"<<setw(2)<< timeinfo->tm_min<<":"<<setw(9)<<timeinfo->tm_sec << "\n";
                    file.close();
                    
        //            copy into portfolio
             int sortChoice;
             cout << "Which algorithm would you like to use to sort the stocks, Bubble sort or Selection sort?" << endl;
             cout << "Enter 1 for bubble sort and enter 2 for selection sort." << endl;
             cin >> sortChoice;
             if (sortChoice == 1) {
                 List->bubblesortList();
             }
             else {
                 List->selectionsortList();
             }
             
                    List->copyToPortfolio();
             

             ofstream hist;
             hist.open("bank_history_transaction.txt", ios::app);
             
             hist <<left<<setw(15) << "Withdrawal" <<left << "$" <<left<<setw(14)<<N1->getTot()<< left<<setw(2) << timeinfo->tm_mon+1<<left<<"/"<<left<<setw(2)<<timeinfo->tm_mday<<left<<"/"<<left<<setw(9)<<timeinfo->tm_year+1900 <<left<<setw(15) << Balance << endl;
             hist.close();
             
             ofstream value;
             value.open("portfolioValue.txt",ios::app);
             value <<  left << TotalValue <<"\t" << seconds << "\n";
             value.close();
                    return 1;
                }
         else{
             do{
                         if(current->getStockName()== name){
                             current->setQuantity(Number);
                             current->setValue(actualPrice);
                             
                             float newExtra = Number*actualPrice;
                             current->setTotal(current->getTot()+newExtra) ;
                             Balance -= newExtra;
                             float TotalList = List->calcTotal();
                             TotalValue = TotalList+Balance;
                             
                             ofstream add("bankBalance.txt");
                             add << Balance<<endl;
                             add.close();
                             
             //                copy into portfolio function
                             int sortChoice;
                             cout << "Which algorithm would you like to use to sort the stocks, Bubble sort or Selection sort?" << endl;
                             cout << "Enter 1 for bubble sort and enter 2 for selection sort." << endl;
                             cin >> sortChoice;
                             if (sortChoice == 1) {
                                 List->bubblesortList();
                             }
                             else {
                                 List->selectionsortList();
                             }
                             List->copyToPortfolio();
             //                write into history;
                             ofstream file;
                             file.open("stock_history_transaction.txt", ios::app);
                             
                             //calcuate the time.
                             time_t seconds;
                             seconds = time(NULL);
                             tm * timeinfo;
                             timeinfo = localtime(&seconds);
                             
                             file << setiosflags(ios::fixed) << setprecision(2);
                             
                             
                             file << std::left << setw(15) << "Buy" << std::left << setw(15) << name << std::left << setw(15) << Number << std::left << setw(1) << "$" << std::left << setw(14) << actualPrice << std::left << setw(1) << "$" << std::left << setw(14) << newExtra<< std::left  <<setw(2)<< timeinfo->tm_hour<<":"<<setw(2)<< timeinfo->tm_min<<":"<<setw(9)<<timeinfo->tm_sec << "\n";
                             file.close();
                             
                             ofstream hist;
                             hist.open("bank_history_transaction.txt", ios::app);
                            
                             hist <<left<<setw(15) << "Withdrawal" <<left << "$" <<left<<setw(14)<<newExtra<< left<<setw(2) << timeinfo->tm_mon+1<<left<<"/"<<left<<setw(2)<<timeinfo->tm_mday<<left<<"/"<<left<<setw(9)<<timeinfo->tm_year+1900 <<left<<setw(15) << Balance << endl;
                             hist.close();
                             
                             ofstream value;
                             value.open("portfolioValue.txt",ios::app);
                             value <<  left << TotalValue <<"\t"<< seconds << "\n";
                             value.close();
                             return 1;
                         }
                 current= current->getNextPtr();
             }while(current!=NULL);
             StockNode* N1 = new StockNode();
                         N1->setStockName(name);
                         N1->setQuantity(Number);
                         N1->setValue(actualPrice);
                         N1->setTotal(N1->getValue()*N1->getQuantity());
                         List->addToEnd(N1);
                         float TotalList = List->calcTotal();
                         Balance -= N1->getTot();
             TotalValue = TotalList+Balance;
                         ofstream add("bankBalance.txt");
                         add << Balance<<endl;
                         add.close();
                         
                         ofstream file;
                         file.open("stock_history_transaction.txt", ios::app);
                         
                         //calcuate the time.
                         time_t seconds;
                         seconds = time(NULL);
                         tm * timeinfo;
                         timeinfo = localtime(&seconds);
                         
                         file << setiosflags(ios::fixed) << setprecision(2);
                         
            
             file << std::left << setw(15) << "Buy" << std::left << setw(15) << name << std::left << setw(15) << Number << std::left << setw(1) << "$" << std::left << setw(14) << actualPrice << std::left << setw(1) << "$" << std::left << setw(14) << N1->getTot()<< std::left  <<setw(2)<< timeinfo->tm_hour<<":"<<setw(2)<< timeinfo->tm_min<<":"<<setw(9)<<timeinfo->tm_sec << "\n";
                         file.close();
                         
             //            copy into portfolio
             int sortChoice;
             cout << "Which algorithm would you like to use to sort the stocks, Bubble sort or Selection sort?" << endl;
             cout << "Enter 1 for bubble sort and enter 2 for selection sort." << endl;
             cin >> sortChoice;
             if (sortChoice == 1) {
                 List->bubblesortList();
             }
             else {
                 List->selectionsortList();
             }
             List->copyToPortfolio();
             
             ofstream hist;
             hist.open("bank_history_transaction.txt", ios::app);
          
             hist <<left<<setw(15) << "Withdrawal" <<left << "$" <<left<<setw(14)<<N1->getTot()<< left<<setw(2) << timeinfo->tm_mon+1<<left<<"/"<<left<<setw(2)<<timeinfo->tm_mday<<left<<"/"<<left<<setw(9)<<timeinfo->tm_year+1900 <<left<<setw(15) << Balance << endl;
             hist.close();
             
             ofstream value;
             value.open("portfolioValue.txt",ios::app);
             value <<  left << TotalValue <<"\t" << seconds << "\n";
             value.close();
             return 1;
         }
    }
}

void StockPortfolio::print(){
    List->printList();
}

int StockPortfolio::Sell(string name, int Number, float lower){
    string arr[2]={"Result_1.txt","Result_2.txt"};
    srand(time(NULL));
    int v = rand()%2;
    string fileName = arr[v];
    float actualPrice = DisplayPrice(arr[v], name);
    if(actualPrice==-1){
        cout<<"wrong symbol"<<endl;
        return -1;
    }
    if(lower>actualPrice){
        cout<<"Fail Too Much demanded"<<endl;
        return -2;
    }
    else{
        StockNode* current = List->getHead();
        
         if(List->size()==0){
             cout<<"NO shares in portfolio"<<endl;
                    return -3;
                }
         else{
             do{
                         if(current->getStockName()== name){
                             if(current->getQuantity()<Number){
                                 cout<<"Not enough shares"<<endl;
                                 return -4;
                             }
                             
                             current->setQuantity(-Number);
                             if(current->getQuantity()==0){
                                 
                                 float newExtra = Number*actualPrice;
                                 Balance += newExtra;
                                 List->removeNode(current);
                                 List->printList();
                                 float TotalList = List->calcTotal();
                                 TotalValue = TotalList+Balance;
                                 
                                 ofstream add("bankBalance.txt");
                                    add << Balance<<endl;
                                    add.close();
                                                             
                //                copy into portfolio function
                                 int sortChoice;
                                 cout << "Which algorithm would you like to use to sort the stocks, Bubble sort or Selection sort?" << endl;
                                 cout << "Enter 1 for bubble sort and enter 2 for selection sort." << endl;
                                 cin >> sortChoice;
                                 if (sortChoice == 1) {
                                     List->bubblesortList();
                                 }
                                 else {
                                     List->selectionsortList();
                                 }
                                    List->copyToPortfolio();
//                write into history;
                                    ofstream file;
                                    file.open("stock_history_transaction.txt", ios::app);
                                                             
                                    //calcuate the time.
                                    time_t seconds;
                                    seconds = time(NULL);
                                    tm * timeinfo;
                                    timeinfo = localtime(&seconds);
                                                             
                                    file << setiosflags(ios::fixed) << setprecision(2);
                                  
                                 
                                 file << std::left << setw(15) << "Sell" << std::left << setw(15) << name << std::left << setw(15) << Number << std::left << setw(1) << "$" << std::left << setw(14) << actualPrice << std::left << setw(1) << "$" << std::left << setw(14) << newExtra<< std::left  <<setw(2)<< timeinfo->tm_hour<<":"<<setw(2)<< timeinfo->tm_min<<":"<<setw(9)<<timeinfo->tm_sec << "\n";
                                    file.close();
                                                            
                                    ofstream hist;
                                    hist.open("bank_history_transaction.txt", ios::app);
                                    
                                 hist <<left<<setw(15) << "Deposit" <<left << "$" <<left<<setw(14)<<newExtra<< left<<setw(2) << timeinfo->tm_mon+1<<left<<"/"<<left<<setw(2)<<timeinfo->tm_mday<<left<<"/"<<left<<setw(9)<<timeinfo->tm_year+1900 <<left<<setw(15) << Balance << endl;
                                    hist.close();
                                 
                                    ofstream value;
                                    value.open("portfolioValue.txt",ios::app);
                                    value << left<< TotalValue <<"\t"<< seconds << "\n";
                                    value.close();
                                 
                                 return 1;
                             }
                             current->setValue(actualPrice);
                             
                             float newExtra = Number*actualPrice;
//                             current->setTotal(current->getTot()-newExtra) ;
                             current->setTotal(current->getQuantity()*current->getValue());
                             Balance += newExtra;
                             float TotalList = List->calcTotal();
                             TotalValue = TotalList+Balance;
                             
                             ofstream add("bankBalance.txt");
                             add << Balance<<endl;
                             add.close();
                             
             //                copy into portfolio function
                            int sortChoice;
                             cout << "Which algorithm would you like to use to sort the stocks, Bubble sort or Selection sort?" << endl;
                             cout << "Enter 1 for bubble sort and enter 2 for selection sort." << endl;
                             cin >> sortChoice;
                             if (sortChoice == 1) {
                                 List->bubblesortList();
                             }
                             else {
                                 List->selectionsortList();
                             }
                             List->copyToPortfolio();
             //                write into history;
                             ofstream file;
                             file.open("stock_history_transaction.txt", ios::app);
                             
                             //calcuate the time.
                             time_t seconds;
                             seconds = time(NULL);
                             tm * timeinfo;
                             timeinfo = localtime(&seconds);
                             
                             file << setiosflags(ios::fixed) << setprecision(2);
                          
                              file << std::left << setw(15) << "Sell" << std::left << setw(15) << name << std::left << setw(15) << Number << std::left << setw(1) << "$" << std::left << setw(14) << actualPrice << std::left << setw(1) << "$" << std::left << setw(14) << newExtra<< std::left  <<setw(2)<< timeinfo->tm_hour<<":"<<setw(2)<< timeinfo->tm_min<<":"<<setw(9)<<timeinfo->tm_sec << "\n";
                             file.close();
                             
                             ofstream hist;
                             hist.open("bank_history_transaction.txt", ios::app);
                             
                             hist <<left<<setw(15) << "Deposit" <<left << "$" <<left<<setw(14)<<newExtra<< left<<setw(2) << timeinfo->tm_mon+1<<left<<"/"<<left<<setw(2)<<timeinfo->tm_mday<<left<<"/"<<left<<setw(9)<<timeinfo->tm_year+1900 <<left<<setw(15) << Balance << endl;
                             hist.close();
                             
                             ofstream value;
                             value.open("portfolioValue.txt",ios::app);
                             value <<  left << TotalValue <<"\t"<< seconds << "\n";
                             value.close();
                             return 1;
                         }
                 current= current->getNextPtr();
             }while(current!=NULL);
             
             cout<<"No such share in the portfolio"<<endl;
             
                         return -1;
         }
    }
}

void StockPortfolio::DisplayPortfolio(){
    cout<<"Cash balance is: "<<Balance<<endl;
    ifstream read("stockPortfolio.txt");
    char line[100];
    while (!read.eof()) {
        read.getline(line, 100);
        cout << line << endl;
    }
    read.close();
    cout<<"Total Portfolio value is: "<<List->calcTotal()+Balance<<endl;
}

void StockPortfolio::viewGraph(){
//    Engine *ep;
//        ep = engOpen(NULL);
//        if (ep == NULL)
//        {
//            cout << "ERROR:engine open failed" << endl;
//            exit(1);
//        }

        
        ifstream open ("portfolioValue.txt");
        vector<double> value;
        vector<double>seconds;
        int count=0;
        while(!open.eof()){
            double x;
            double y;
            /*if(count%2==0){*/
                open>>x;
                value.push_back(x);
            //}
            //else{
                open>>y;
                seconds.push_back(y);
            //}
            //count++;
        }
       /* for(int i=0;i<value.size();i++){
            cout<<value[i]<<"\t";
        }
        for(int i=0;i<seconds.size();i++){
            cout<<seconds[i]<<endl;
        }*/
  
        int timeSize = seconds.size();
        int valueSize = value.size();
        double *timeArray = new double[timeSize];
        double *valueArray = new double[valueSize];

        for (int i = 0; i < seconds.size(); i++) {
            timeArray[i] = seconds[i];
        }
	for (int i = 0; i < value.size(); i++) {
		valueArray[i] = value[i];
		}
	cout << "rfsg";
//        mxArray *A;
//        A = mxCreateDoubleMatrix(1, seconds.size(), mxREAL);
//        memcpy((void*)mxGetPr(A), (void *)timeArray, sizeof(double) * seconds.size());
//        mxArray *B;
//        B = mxCreateDoubleMatrix(1, value.size(), mxREAL);
//        memcpy((void*)mxGetPr(B), (void *)valueArray, sizeof(double) * value.size());
//		cout << "ters";
//        engPutVariable(ep, "time", A);
//        engPutVariable(ep, "value", B);
//        engEvalString(ep, "plot(time, value)");
//		cout << "trhhs";
//        system("pause");
//
//        mxDestroyArray(A);
//        engEvalString(ep, "close;");
//
//        engClose(ep);
		return;
}
    

