//
//  main.cpp
//  Homework 10
//
//  Created by Shounak Rangwala on 11/9/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "dataClass.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main(int argc, const char * argv[]) {
    List L1;

    while(true){
        cout<<"welcome to shopping list program"<<endl;
        cout<<"Please select the option:"<<endl;
        cout<<"1.  Add a new node at the beginning"<<endl;
        cout<<"2.  Add a new node at the end"<<endl;
        cout<<"3.  Remove the beginning node"<<endl;
        cout<<"4.  Remove the end node"<<endl;
        cout<<"5.  Remove a node from the list by entering an item number"<<endl;
        cout<<"6.  Remove a node from the list by entering an item name"<<endl;
        cout<<"7.  Print out the list"<<endl;
        cout<<"8.  Quit the program"<<endl;
        int choice;
        cin>>choice;
        
        string Name;
        int productNumber;
        switch(choice){
            case 1:
            {
                cout<<"Enter the product name: "<<endl;
                cin>>Name;
                cout<<"Enter the product number: "<<endl;
                cin>>productNumber;
                Data D1(productNumber,Name);
                L1.addToStart(new Node(D1));
                cout<<endl;
                cout<<"The linked list is: "<<endl;
                L1.printList();
                cout<<endl;
                break;
            }
            case 2:{
                cout<<"Enter the product name: "<<endl;
                cin>>Name;
                cout<<"Enter the product number: "<<endl;
                cin>>productNumber;
                Data D1(productNumber,Name);
                L1.addToEnd(new Node(D1));
                cout<<endl;
                cout<<"The linked list is: "<<endl;
                L1.printList();
                cout<<endl;
                break;
            }
            case 3:{
                L1.removeFromStart();
                cout<<endl;
                cout<<"The linked list is: "<<endl;
                L1.printList();
                cout<<endl;
                break;
            }
            case 4:{
                L1.removeFromEnd();
                cout<<endl;
                cout<<"The linked list is: "<<endl;
                L1.printList();
                cout<<endl;
                break;
            }
            case 5:{
                cout<<"Enter the item number to search for and delete :"<<endl;
                cin>>productNumber;
                L1.removeNodeFromNumber(productNumber);
                cout<<endl;
                cout<<"The linked list is: "<<endl;
                L1.printList();
                cout<<endl;
                break;
            }
            case 6:{
                cout<<"Enter the item name to search and delete :"<<endl;
                cin>>Name;
                L1.removeNodeFromName(Name);
                cout<<endl;
                cout<<"The linked list is: "<<endl;
                L1.printList();
                cout<<endl;
                break;
            }
            case 7:
                cout<<endl;
                cout<<"The linked list is: "<<endl;
                L1.printList();
                cout<<endl;
                break;
            case 8:
                return 0;
            default:
                return 0;
        }
    }

    return 0;
}
