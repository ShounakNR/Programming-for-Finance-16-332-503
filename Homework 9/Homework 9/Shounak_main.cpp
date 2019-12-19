//
//  main.cpp
//  Homework 9
//Programming for finance 16:332:503
//  Created by Shounak Rangwala on 11/2/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include "User.h"
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    float normal = 1,overnight = 4,twoday = 2.5;
    
    //Set the cost of delivery in per ounces
    cout<<"Package delivery service"<<endl<<endl;
    cout<<"Cost per ounce for a package: "<<normal<<endl;
    cout<<"Additional cost for two-day delivery: "<<twoday<<endl;
    cout<<"Additional cost for overnight delivery: "<<overnight<<endl;
    
//    Create 4 users who will send and recieve packages
    User Jill=User("Jill Potter","1 Davidson Road","Piscataway","NJ","08854");
    User Jack = User("Jack Potter","23 Belledore Ave","Princeton","NJ","09954");
    User Shaun = User("Shaun Hadley", "334 Empire State", "NYC", "NY", "00001");
    User DJ = User("DJ", "23 Ortley Road", "San Jose", "CA", "23213");
    
//    initialize the package objects 3 objects, 1 of each type
    Package normalPkg (Jill,Jack,12,normal);
    TwoDayPackage twoDayPkg (Shaun,DJ,20,normal,twoday);
    OvernightPackage overPkg (Shaun,Jill,15,normal,overnight);
    
    Package* ptr;// pointer of Package type to go through the vector
    vector<Package*> packageCollection;//create a vector of references to the 3 packages
    float TotalCost = 0;//variable to get the total cost later
    packageCollection.push_back(&normalPkg);
    packageCollection.push_back(&twoDayPkg);
    packageCollection.push_back(&overPkg);
    
    for(int i=0;i<packageCollection.size();i++){
        ptr = packageCollection[i];
        cout<<"Package "<<i+1<<endl;
        
        //Print out the name and address of the sender and the reciever in a proper format
        cout<<"Sender:"<<endl;
        cout<<ptr->getSender().getName()<<endl;
        cout<<ptr->getSender().getAddress()<<","<<endl;
        cout<<ptr->getSender().getCity()<<","<<ptr->getSender().getState()<<","<<ptr->getSender().getZip()<<endl<<endl;;
        
        cout<<"Receiver:"<<endl;
        cout<<ptr->getReceiver().getName()<<endl;
        cout<<ptr->getReceiver().getAddress()<<","<<endl;
        cout<<ptr->getReceiver().getCity()<<","<<ptr->getReceiver().getState()<<","<<ptr->getReceiver().getZip()<<endl<<endl;
        
        cout<<"Weight of the package: "<<ptr->getWeight()<<endl;
        cout<<"Type of delivery: "<<ptr->getTypeofDelivery()<<endl;
        cout<<"Cost: "<<ptr->calculateCost()<<endl<<endl<<endl;
        
        TotalCost += ptr->calculateCost();
    }
    
    cout<<"The total cost of all packages is : "<<TotalCost<<endl;
    
    
    return 0;
}
