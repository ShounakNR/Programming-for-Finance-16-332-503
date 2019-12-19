//
//  main.cpp
//  Homework 5
//  programming for finance 16:332:503.
//  Created by Shounak Rangwala on 10/7/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> recursiveSquares (vector<int> ptr, int n){
    while(n>1){
        vector <int> innerVect = ptr;
        int i;
        for(i=0;i<innerVect.size();i++){
            if(innerVect[i]==1){
                break;
            }
        }
        if(n%2==0 ){
            innerVect.insert(innerVect.begin()+i+1,n*n);
        }
        else if (n%2==1 ){
            if(i==0){
                innerVect.insert(innerVect.begin(), n*n);
            }
            else {
                innerVect.insert(innerVect.begin()+i,n*n);
            }
        }
        return recursiveSquares(innerVect, n-1);
    }
    return ptr;
}
/*list<int> trial(list<int> ptr){
    list<int> one = ptr;
    one.push_front(1);
    one.push_front(0);
    return one;
}*/
void printSquares (int n){
    
    if(n==1){
        cout<<1;
    }
    while(n>1){
        if(n%2==0){
            printSquares(n-1);
            cout<<","<<n*n;
            break;
        }
        else{
            cout<<n*n<<",";
            printSquares(n-1);
            break;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    int length ;
    cout<<"enter n: ";
    cin>>length;
    vector<int> arr;
    vector<int>ans;
    
   /* arr.push_back(1);
    ans=recursiveSquares(arr,length);
//    ans= trial(arr);

    for(vector<int>::iterator i=ans.begin();i!=ans.end();i++){
        cout<<*i<<",";
    }cout<<endl;*/
    printSquares(length);
    return 0;
}
