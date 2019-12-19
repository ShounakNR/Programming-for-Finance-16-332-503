//
//  main.cpp
//  Homework3 Matrix calculations (with arrays)
//  Programming for finance 16:332:503.
//  Created by Shounak Rangwala on 9/21/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int * inputDimensions(){
    static int dimensions[2];
    cout << "enter the number of the rows: "<<endl;
    cin >> dimensions[0];
    while(dimensions[0]<0 || dimensions[0]>10){
        cout<<"out of bounds enter dimension less than 10"<<endl;
        cin>> dimensions[0];
    }
    cout <<"enter the number of the columns: "<<endl;
    cin >> dimensions[1];
    while(dimensions[1]<0 || dimensions[1]>10){
        cout<<"out of bounds enter dimension less than 10"<<endl;
        cin>> dimensions[1];
    }
    
    return dimensions;
}

void inputValues( int *rows, int *columns, double arr[][10]){
    int rowNumbers = *rows;
    int columnNumbers = *columns;
    
    for(int i=0;i<rowNumbers;i++){
        for(int j=0;j<columnNumbers;j++){
            cout<< "\t";
            cin>> arr[i][j];
        }
    }
}

void DisplayValues( int *rows, int *columns, double arr[][10]){
    int rowNumbers = *rows;
    int columnNumbers = *columns;
    for(int i=0;i<rowNumbers;i++){
        for(int j=0;j<columnNumbers;j++){
            cout<< setw(8)<<arr[i][j];
        }
        cout<<endl;
    }
}

void Addition(){
    int *Mat1Dims = inputDimensions();
    int row1 = *Mat1Dims, column1 = *(Mat1Dims+1);
    double Mat1 [10][10];
    inputValues(Mat1Dims, Mat1Dims+1, Mat1);
    cout<<"your input is:"<<endl;
    DisplayValues(Mat1Dims, Mat1Dims+1, Mat1);
    int *Mat2Dims = inputDimensions();
    int row2 = *Mat2Dims, column2 = *(Mat2Dims+1);
    if((row1 != row2) || (column1 != column2)){
        cout<<"operation not supported"<<endl;
        return;
    }
    double Mat2 [10][10];

    inputValues(Mat2Dims, Mat2Dims+1, Mat2);
    cout<<"your input is:"<<endl;
    DisplayValues(Mat2Dims, Mat2Dims+1, Mat2);
    double result [10][10];
    
    for(int i=0;i<row2;i++){
        for(int j=0;j<column2;j++){
            result[i][j] = Mat1[i][j]+Mat2[i][j];
        }
    }
    cout<<"The result is:"<<endl;
    DisplayValues(Mat2Dims, Mat2Dims+1, result);
    return;
};

void Subtraction(){
    int *Mat1Dims = inputDimensions();
    int row1 = *Mat1Dims, column1 = *(Mat1Dims+1);
    double Mat1 [10][10];
    inputValues(Mat1Dims, Mat1Dims+1, Mat1);
    cout<<"your input is:"<<endl;
    DisplayValues(Mat1Dims, Mat1Dims+1, Mat1);
    int *Mat2Dims = inputDimensions();
    int row2 = *Mat2Dims, column2 = *(Mat2Dims+1);
    if((row1 != row2) || (column1 != column2)){
        cout<<"operation not supported"<<endl;
        return;
    }
    double Mat2 [10][10];
    
    inputValues(Mat2Dims, Mat2Dims+1, Mat2);
    cout<<"your input is:"<<endl;
    DisplayValues(Mat2Dims, Mat2Dims+1, Mat2);
    double result [10][10];
    
    for(int i=0;i<row2;i++){
        for(int j=0;j<column2;j++){
            result[i][j] = Mat1[i][j]-Mat2[i][j];
        }
    }
    cout<<"The result is:"<<endl;
    DisplayValues(Mat2Dims, Mat2Dims+1, result);
    return;
};

void Multiplication(){
    int *Mat1Dims = inputDimensions();
    int row1 = *Mat1Dims, column1 = *(Mat1Dims+1);
    double Mat1 [10][10];
    inputValues(Mat1Dims, Mat1Dims+1, Mat1);
    cout<<"your input is:"<<endl;
    DisplayValues(Mat1Dims, Mat1Dims+1, Mat1);
    int *Mat2Dims = inputDimensions();
    int row2 = *Mat2Dims, column2 = *(Mat2Dims+1);
    if(row2!=column1){
        cout<<"operation not supported"<<endl;
        return;
    }
    double Mat2 [10][10];
    
    inputValues(Mat2Dims, Mat2Dims+1, Mat2);
    cout<<"your input is:"<<endl;
    DisplayValues(Mat2Dims, Mat2Dims+1, Mat2);
    double result [10][10];
    for(int i=0;i<row1;i++){
        for(int j=0;j<column2;j++){
            result[i][j]=0;
        }
    }
    
    for(int i=0;i<row1;i++){
        for(int j=0;j<column2;j++){
            for(int k=0;k<column1;k++){
                result[i][j] += Mat1[i][k]*Mat2[k][j];
            }
        }
    }
    cout<<"The result is:"<<endl;
    DisplayValues(Mat1Dims, Mat2Dims+1, result);
    return;
};

void Transpose(){
    int *Mat1Dims = inputDimensions();
    int row1 = *Mat1Dims, column1 = *(Mat1Dims+1);
    double Mat1 [10][10];
    inputValues(Mat1Dims, Mat1Dims+1, Mat1);
    cout<<"your input is:"<<endl;
    DisplayValues(Mat1Dims, Mat1Dims+1, Mat1);
    double result [10][10];
    
    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            result[j][i] = Mat1[i][j];
        }
    }
    cout<<"The result is:"<<endl;
    DisplayValues(Mat1Dims+1, Mat1Dims, result);
    return;
};

void Determinant(){
    int *Mat1Dims = inputDimensions();
    int row1 = *Mat1Dims, column1 = *(Mat1Dims+1);
    if (!(row1==3 && column1==3 && row1 == column1)){
        cout<<"operation  not supported"<<endl;
        return;
    }
    double Mat1 [10][10];
    inputValues(Mat1Dims, Mat1Dims+1, Mat1);
    cout<<"your input is:"<<endl;
    DisplayValues(Mat1Dims, Mat1Dims+1, Mat1);
    double result;
    
    result = Mat1[0][0]*(Mat1[1][1] * Mat1[2][2]-Mat1[2][1]*Mat1[1][2]) - Mat1[0][1]*(Mat1[1][0]*Mat1[2][2] - Mat1[2][0]*Mat1[1][2]) + Mat1[0][2]*(Mat1[1][0]*Mat1[2][1]-Mat1[2][0]*Mat1[1][1]);
    cout<<"The result is: "<< result<<endl;
    
    return;
};

void Inverse(){
    int *Mat1Dims = inputDimensions();
    int row1 = *Mat1Dims, column1 = *(Mat1Dims+1);
    if (!(row1==3 && column1==3 && row1 == column1)){
        cout<<"operation  not supported"<<endl;
        return;
    }
    double Mat1 [10][10];
    inputValues(Mat1Dims, Mat1Dims+1, Mat1);
    cout<<"your input is:"<<endl;
    DisplayValues(Mat1Dims, Mat1Dims+1, Mat1);
    double result;
    
    result = Mat1[0][0]*(Mat1[1][1] * Mat1[2][2]-Mat1[2][1]*Mat1[1][2]) - Mat1[0][1]*(Mat1[1][0]*Mat1[2][2] - Mat1[2][0]*Mat1[1][2]) + Mat1[0][2]*(Mat1[1][0]*Mat1[2][1]-Mat1[2][0]*Mat1[1][1]);
    
    if(result ==0){
        cout<<" operation not possible"<<endl;
        return;
    }
    
    double transposeMatrix[3][3];
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column1; j++) {
            transposeMatrix[j][i] = Mat1[i][j];
        }
    }
    
    //Calculate 2-complement of matrix.
    double complementMatrix[3][3];
    complementMatrix[0][0] = transposeMatrix[1][1] * transposeMatrix[2][2] - transposeMatrix[1][2] * transposeMatrix[2][1];
    complementMatrix[0][1] = - (transposeMatrix[1][0] * transposeMatrix[2][2] - transposeMatrix[1][2] * transposeMatrix[2][0]);
    complementMatrix[0][2] = transposeMatrix[1][0] * transposeMatrix[2][1] - transposeMatrix[1][1] * transposeMatrix[2][0];
    
    complementMatrix[1][0] = - (transposeMatrix[0][1] * transposeMatrix[2][2] - transposeMatrix[0][2] * transposeMatrix[2][1]);
    complementMatrix[1][1] = transposeMatrix[0][0] * transposeMatrix[2][2] - transposeMatrix[0][2] * transposeMatrix[2][0];
    complementMatrix[1][2] = - (transposeMatrix[0][0] * transposeMatrix[2][1] - transposeMatrix[0][1] * transposeMatrix[2][0]);
    
    complementMatrix[2][0] = transposeMatrix[0][1] * transposeMatrix[1][2] - transposeMatrix[0][2] * transposeMatrix[1][1];
    complementMatrix[2][1] = - (transposeMatrix[0][0] * transposeMatrix[1][2] - transposeMatrix[0][2] * transposeMatrix[1][0]);
    complementMatrix[2][2] = transposeMatrix[0][0] * transposeMatrix[1][1] - transposeMatrix[0][1] * transposeMatrix[1][0];
    
    //The pre-result is 2-complement times 1/det(matrix).
    double preInverseMatrix[10][10];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            preInverseMatrix[i][j] = complementMatrix[i][j] / result;
        }
    }
    
    //The result is transpose of pre-result.
    double inverseMatrix[10][10];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inverseMatrix[i][j] = preInverseMatrix[j][i];
        }
    }
    cout<<" The ans is: "<<endl;
    DisplayValues(Mat1Dims, Mat1Dims+1, inverseMatrix);
    return;
};


int main(int argc, const char * argv[]) {

    while(true){
        int choice;
        cout<< "Menu"<< endl;
        cout<<"Choice 1: Addition"<<endl;
        cout<<"Choice 2: Subtraction"<<endl;
        cout<<"Choice 3: Multiplication"<<endl;
        cout<<"Choice 4: Transpose"<< endl;
        cout<<"Choice 5: Determinant"<< endl;
        cout<<"Choice 6: Inverse"<< endl;
        cout<<"Choice 7: Quit" << endl;
        cout<<"enter your choice"<<endl;
        cin>> choice;
        
        switch(choice){
            case 1: Addition();
                break;
            case 2: Subtraction();
                break;
            case 3: Multiplication();
                break;
            case 4: Transpose();
                break;
            case 5: Determinant();
                break;
            case 6: Inverse();
                break;
            case 7: return 0;
        }
    }
}





