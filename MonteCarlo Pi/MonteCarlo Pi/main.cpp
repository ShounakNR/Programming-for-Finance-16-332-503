//  MonteCarlo Pi
//  Programming for finance 16:332:503
//  Monte Carlo Homework Assignment
//  Created by Shounak Rangwala on 9/15/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
#include <iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    ofstream mypoints {"RandomPoints.txt", ios::out};
    
    if(!mypoints){
        cerr<<"file could not be opened"<<endl;
        exit(EXIT_FAILURE);
    }
    int intervals;
    do{
        cout <<"Enter number of intervals atleast 100"<<endl;
        cin>> intervals;
    }while(intervals<100);
    
    double x_coord,y_coord;
    int countIn=0;
    srand(time(0));
    
    for (int i=0;i<intervals;i++){
        x_coord = double(rand())/RAND_MAX;
        y_coord = double(rand())/RAND_MAX;
        if(x_coord*x_coord+y_coord*y_coord <=1){
            countIn++;
        }
//        cout<< x_coord<< "\t"<< y_coord <<endl;
        mypoints<<setprecision(5)<<x_coord<<"\t"<<setprecision(5)<<y_coord<<endl;
    }
    cout << "Value of PI is approximately: "<<double(countIn*4)/intervals;
    return 0;
}
