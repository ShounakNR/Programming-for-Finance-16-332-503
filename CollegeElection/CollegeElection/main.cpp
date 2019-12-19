//
//  Programming for finance 16:332:503
//  CollegeElection
//  InClass assignment 3

//  Created by Shounak Rangwala on 9/21/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <typeinfo>
using namespace std;

int main(int argc, const char * argv[]) {
    int votesArr [20];
    int ans;
//    THis code snippet takes 20 random integers from 1 to 5 as the array of votes of 20 people
//    So instead of user inputting the values, we give the ready made array to the
//    srand(time(0));
//    for (int i=0;i<20;i++){
//        votesArr[i] = rand()%5 +1;
//    }
    
    for(int i=0;i<20;i++){
        cout<< "PLease enter the candidate you are voting for (1-5): "<<endl;
        cin>>ans;
        while(ans>5 || ans<1){
            cout<<"pls enter correct number"<<endl;
            cin>>ans;
        }
        votesArr[i]=ans;
    }
    
    cout<<endl<<endl;
    int numberOfCandidates=5;
    int numberofVoters = 20;
    int CrosslistArr [5][20]={0};
    
    for (int i=0;i<numberofVoters;i++){
        CrosslistArr[votesArr[i]-1][i] = 1;
    }
/*    for (int i=0;i<numberOfCandidates;i++){
        for(int j=0;j<numberofVoters;j++){
            cout<< CrosslistArr[i][j]<<"\t";
        }
        cout<<endl;
    }
 */
    int resultArr[5];
    for (int i=0;i<numberOfCandidates;i++){
        int sum =0;
        for(int j=0;j<numberofVoters;j++){
            sum += CrosslistArr[i][j];
        }
        resultArr[i]=sum;
        cout<<"candidate "<< i+1<<" has got : "<<sum<<endl;
    }
    int max=0,winner=0;
    for (int i=0;i<sizeof(resultArr)/sizeof(resultArr[0]);i++){
        if(resultArr[i]>=max){
            max=resultArr[i];
            winner=i+1;
        }

    }
    
    for (int i=0;i<sizeof(resultArr)/sizeof(resultArr[0]);i++){
        if (max==resultArr[i] && i!=winner-1){
            cout<<"No winners"<<endl;
            break;
        }
        else if(i == sizeof(resultArr)/sizeof(resultArr[0])-1){
            cout<<"winner is candidate number "<< winner<<endl;
        }
    }
    
    return 0;
}
