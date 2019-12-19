//
//  IntegerSet.h
//  InClass5 Pff
//
//  Created by Shounak Rangwala on 10/19/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#ifndef IntegerSet_h
#define IntegerSet_h

class IntegerSet{
    public:
    IntegerSet( ); // constructor

/* Write a member funcion prototype for UnionOfSets */

    void inputSet(); // read values from user
    
    IntegerSet unionOfSets (IntegerSet);
    IntegerSet intersectionOfSets (IntegerSet);
    void printSet() ;

    private:
    int set[ 101 ]; // range of 0 - 100

// determines a valid entry to the set
    int validEntry( int x){
        return ( x >= 0 && x <= 100 );
    } // end function validEntry
};


#endif /* IntegerSet_h */
