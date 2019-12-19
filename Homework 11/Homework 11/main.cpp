//
//  main.cpp
//  Homework 11
//  Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/19/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "Booklist_template.h"
#include <string.h>
using namespace std;



int main(int argc, const char * argv[]) {
    BookList<string> bl;
    string bookList [20] = {""};
    
    bl.arr=bookList;
    
     while (true) {
         cout<<"Welcome to the booklist program"<<endl;
         cout<<"What would you like to do"<<endl;
         cout<<"1. Add an element to end of list"<<endl;
         cout<<"2. Add an element at a location"<<endl;
         cout<<"3. find an element by book name (linear search)"<<endl;
         cout<<"4. find an element by book name (binary search)"<<endl;
         cout<<"5. delete an element at position"<<endl;
         cout<<"6. delete an element by name"<<endl;
         cout<<"7. sort the list (using selection sort)"<<endl;
         cout<<"8. sort the list (using bubble sort)"<<endl;
         cout<<"9. print the list"<<endl;
         cout<<"0. exit"<<endl;

         int choice,location;
         cin>>choice;
         switch (choice) {
             case 1:
                 bl.insertAtEnd(bl.inputElement());
                 
                 bl.printList();
                 break;
             case 2:
                 bl.insertAtPos(bl.inputElement(),bl.inputPosition());
                 
                 bl.printList();
                 break;
             case 3:
                 location = bl.linearSearch(bl.inputElement());
                 if(location ==-1){
                     cout<<"element is not in list"<<endl;
                 }
                 cout<<"The element is present at "<<location +1<<endl;
                 break;
             case 4:
                 if(!bl.isSorted()){
                     bl.bubbleSort();
                 }
                 location = bl.binarySearch(0,bl.inputElement());
                 if(location == -1){
                     cout<<"element not in list"<<endl;
                 }
                 cout<<"The element is present at "<<location+1<<endl;
                 break;
             case 5:
                 bl.deleteFromPosition(bl.inputPosition());
                 
                 bl.printList();
                 break;
             case 6:
                 bl.deleteFromLabel();
                 
                 bl.printList();
                 break;
             case 7:
                 bl.selectionSort();
                 bl.printList();
                 break;
             case 8:
                 bl.bubbleSort();
                 bl.printList();
                 break;
             case 9:
                 bl.printList();
                 break;
             case 0:
                 return 0;

         }
    }
}
