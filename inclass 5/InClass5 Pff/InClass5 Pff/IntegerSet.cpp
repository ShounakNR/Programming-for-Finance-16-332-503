//
//  IntegerSet.cpp
//  InClass5 Pff
//
//  Created by Shounak Rangwala on 10/19/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

#include "IntegerSet.h"
/* Write include directive for IntegerSet.h here */

// constructor
IntegerSet::IntegerSet(){
    for ( int i = 0; i < 101; i++ ) set[ i ] = 0;
} // end IntegerSet constructor

// input a set from the user
void IntegerSet::inputSet(){
    int number;

    do{
        cout << "Enter an element (-1 to end): ";
        cin >> number;

        if ( validEntry( number ) )
            set[ number ] = 1;
        else if ( number != -1 )
            cout << "Invalid Element\n";
    } while ( number != -1 ); // end do...while

    cout << "Entry complete\n";
} // end function inputSet

// prints the set to the output stream
void IntegerSet::printSet(){
    cout <<"{"<<" ";

    for (int u = 0; u < 101; u++ )
        if ( set[ u ] ) cout << u <<" ";

    cout << "}" << endl;
} // end function printSet

/* Write definition for unionOfSets */
IntegerSet IntegerSet::unionOfSets(IntegerSet b){
    IntegerSet result;
    for(int i=0;i<101;i++){
        if(set[i]==1 || b.set[i]==1){
            result.set[i]=1;
        }
        else if(set[i]==0 && b.set[i]==0){
            result.set[i]=0;
        }
    }
    return result;
}

/* Write definition for intersectionOfSets */
IntegerSet IntegerSet::intersectionOfSets(IntegerSet b){
    IntegerSet result;
    for(int i=0;i<101;i++){
        if(set[i]==1 && b.set[i]==1){
            result.set[i]=1;
        }
        else if(set[i]==0 || b.set[i]==0){
            result.set[i]=0;
        }
    }
    return result;
}

