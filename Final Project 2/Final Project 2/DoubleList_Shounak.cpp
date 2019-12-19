//
//  DoubleList.cpp
//  Final Project
//
//  Created by Shounak Rangwala on 11/24/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <string>
#include "DoubleList.h"
#include <fstream>
#include <iomanip>


DoubleList::DoubleList(){
    listsize = 0;
    head= NULL;
    tail=NULL;
}

int DoubleList::size(){
    return listsize;
}

void DoubleList::addToEnd(StockNode * N1){
    if(listsize==0){
        head = tail = N1;
        N1->setPrevPtr(NULL);
        
    }
    else{
        StockNode* temp = tail;
        tail->setNextPtr(N1);
        tail = N1;
        tail->setPrevPtr(temp);
        tail->setNextPtr(NULL);
    }
    
    listsize++;
}

void DoubleList::printList(){
    if(listsize==0){
        cout<<"Bazinga! List is empty"<<endl;
    }
    else{
        StockNode* current = head;
        do {
            cout<<current->getStockName()<<"\t"<<current->getQuantity()<<"\t"<<current->getTot()<<endl;
            current = current->getNextPtr();
        }while (current!=NULL);
    }
}

void DoubleList::removeNode(StockNode* current){
    if(listsize==0){
        cout<<"get real nub"<<endl;
    }
    else{
        if(current==head){
            removeFromStart(current);
        }
        else if(current!=NULL && current!= tail){
             (current->getPrevPtr())->setNextPtr(current->getNextPtr()) ;
             (current->getNextPtr())->setPrevPtr(current->getPrevPtr());
             listsize--;
             delete current;
        }
        else if(current==tail){
            removeFromEnd(current);
        }
        
        else if(current==NULL){
            
            cout<<"Not found"<<endl;
            return;
        }
        
       
    }
        
}

void DoubleList::removeFromEnd(StockNode* current){
    if(listsize==0){
        return;
    }
    if(head==tail){
        head = tail = 0;
        listsize--;
    }
    else{
        tail = current->getPrevPtr();
        tail->setNextPtr(NULL);
        listsize--;
    }
}

void DoubleList::removeFromStart(StockNode* current){
    if(listsize==0){
        return;
    }
    if(head==tail){
        head = tail = 0;
        listsize--;
    }
    else{
        head = current->getNextPtr();
        head->setPrevPtr(NULL);
        listsize--;
    }
}

float DoubleList::calcTotal(){
    float res=0;
    if (listsize==0) return 0;
    StockNode* current =head;
    do{
        
        res += current->getTot();
        current = current->getNextPtr();
    }while(current!=NULL);
    
    return res;
}

StockNode* DoubleList ::getHead(){
    return head;
}

StockNode* DoubleList:: getTail(){
    return tail;
}

void DoubleList::copyToPortfolio(){
    ofstream file;
    file.open("stockPortfolio.txt");
    file << std::left << setw(20) << "Company Symbol" << std::left << setw(10) << "Number" << std::left << setw(20) << "Price-per-share" << std::left << setw(10) << "Total value" << "\n";
    StockNode *ptr = head;
    
    while (ptr != NULL) {
        file << std::left << setw(20) << ptr->getStockName() << std::left << setw(10) << ptr->getQuantity() <<  std::left << setw(20) << ptr->getValue() << std::left << setw(20) << ptr->getTot() << "\n";
        ptr = ptr->getNextPtr();
    }
    file.close();
}

void DoubleList::bubblesortList(){
    StockNode *ptr = head;
    StockNode *iter = head;
    for (int i = 0; i < listsize ; i++) {
        for (int j = 0; j < listsize-i-1; j++) {
            if (ptr->getTot() < ptr->getNextPtr()->getTot()) {
                swap(ptr->getNextPtr(), ptr);
//                string temp_comSymbol = ptr->getStockName();
//                double temp_price = ptr->getValue();
//                int temp_shares = ptr->getQuantity();
//                float totalNodeValue = ptr->getTot();
//
//                ptr->setStockName(ptr->getNextPtr()->getStockName());
//                ptr->setValue(ptr->getNextPtr()->getValue());
//
//                ptr->NumberOfStocks = ptr->getNextPtr()->getQuantity();
//                ptr->setTotal(ptr->getNextPtr()->getTot());
//
//                ptr->getNextPtr()->setStockName(temp_comSymbol);
//                ptr->getNextPtr()->setValue(temp_price);
//                ptr->getNextPtr()->NumberOfStocks=temp_shares;
//                ptr->getNextPtr()->setTotal(totalNodeValue);
            }
            ptr = ptr->getNextPtr();
        }
        ptr = iter;
    }
}

void DoubleList:: swap (StockNode* a, StockNode* b){
    StockNode* temp = new StockNode();
//    int z = temp->getQuantity();
    temp->setQuantity(b->getQuantity());
    temp->setValue(b->getValue());
    temp->setStockName(b->getStockName());
    temp->setTotal(b->getTot());
    
    b->setQuantity(a->getQuantity()-b->getQuantity());
    b->setValue(a->getValue());
    b->setStockName(a->getStockName());
    b->setTotal(a->getTot());
    
    a->setQuantity(temp->getQuantity()-a->getQuantity());
    a->setValue(temp->getValue());
    a->setStockName(temp->getStockName());
    a->setTotal(temp->getTot());
    
}

void DoubleList::selectionsortList(){
    StockNode* temp = head;
    
      // Traverse the List
      while (temp) {
          StockNode* max = temp;
          StockNode* r = temp->next;
    
          // Traverse the unsorted sublist
          while (r) {
              if (max->getTot() < r->getTot())
                  max= r;
    
              r = r->next;
          }
    
          // Swap Data
          swap (max,temp);
          temp = temp->next;
      }
}
