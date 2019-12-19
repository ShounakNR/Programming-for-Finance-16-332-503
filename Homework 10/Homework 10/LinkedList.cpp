//
//  LinkedList.cpp
//  Homework 10
//
//  Created by Shounak Rangwala on 11/9/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;

List::List():head(0),tail(0){
    listSize = 0;
}

void List::addToStart(Node * N1){
    if(listSize==0){
        head = tail = N1;
    }
    else{
        N1->setptr(head);
        head = N1;
        
    }
    listSize++;
}

void List::addToEnd(Node * N1){
    if(listSize==0){
        head = tail = N1;
    }
    else{
        tail->setptr(N1);
        tail = N1;
    }
    
    listSize++;
}

void List::removeFromStart(){
    if(listSize==0){
        return;
    }
    if(head==tail){
        head = tail = 0;
        listSize--;
    }
    else{
        Node* temp = head;
        head = head->getptr();
        delete temp;
        listSize--;
    }
    
}

void List::removeFromEnd(){
    if(listSize==0){
        return;
    }
    if(head==tail){
        head = tail = 0;
        listSize--;
    }
    else{
        Node* current = head;
        Node* temp = tail;
        while(current->getptr()!=tail){
            current = current->getptr();
        }
        tail = current;
        tail->setptr(NULL);
        delete temp;
        listSize--;
    }
    
}

void List::printList(){
    if(listSize==0){
        cout<<"Bazinga! List is empty"<<endl;
    }
    else{
        Node* current = head;
        do {
            cout<<current->getNumber()<<"\t"<<current->getName()<<endl;
            current = current->getptr();
        }while (current!=NULL);
    }
    
}

void List::removeNodeFromName(string s){
    if(listSize==0){
        cout<<"get real nub"<<endl;
    }
    else{
        Node* current = head;
        Node* prev =0;
        while(current!=NULL){
            if(current->getName()!=s){
                prev = current;
                current = current->getptr();
            }
            else if(current->getName()==s){
                break;
            }
        }
        if(current==head){
            removeFromStart();
        }
        else if(current!=NULL && current!= tail){
            prev->setptr(current->getptr());
            delete current;
            listSize--;
        }
        else if(current==tail){
            removeFromEnd();
        }
        
        else if(current==NULL){
            
            cout<<"Not found"<<endl;
            return;
        }
    }
}

void List::removeNodeFromNumber(int i){
    
    if(listSize==0){
        cout<<"get real nub"<<endl;
    }
    else{
        Node* current = head;
        Node* prev =0;
        while(current!=NULL){
            if(current->getNumber()!=i){
                prev = current;
                current = current->getptr();
            }
            else if(current->getNumber()==i){
                break;
            }
        }
        if(current==head){
            removeFromStart();
        }
        else if(current!=NULL && current!= tail){
            prev->setptr(current->getptr());
            delete current;
            listSize--;
        }
        else if(current==tail){
            removeFromEnd();
        }
        
        else if(current==NULL){
            
            cout<<"Not found"<<endl;
            return;
        }
    }
}


Node* List::getHead(){
    return head;
}
Node* List::getTail(){
    return tail;
}

int List::size(){
    return listSize;
}
