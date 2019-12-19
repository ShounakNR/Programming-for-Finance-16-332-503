//
//  main.cpp
//  Inclass-4 Recursion
//  Programming for finance 16:332:503
//  Created by Shounak Rangwala on 10/5/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int countBinStr(int stringSize){
    if (stringSize == 1){
        return 2;
    }
    else if(stringSize ==0){
        return 1;
    }
    else{
        return countBinStr(stringSize-2)+countBinStr(stringSize-1);
    }
}
int main(int argc, const char * argv[]) {
    while(true){
        int stringLen;
        cout<<"enter the length of the binary string: "<<endl;
        cin>> stringLen;
        if(stringLen<1){
            cout<<"dimension out of bounds"<<endl;
            continue;
        }
        int result = countBinStr(stringLen);
        cout<< "Number of binary string made are: "<<result<<endl;
        
    }
    return 0;
}
