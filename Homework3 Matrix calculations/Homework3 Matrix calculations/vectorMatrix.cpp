//
//  vectorMatrix.cpp
//  Homework3 Matrix calculations (with vectors)
//  Programming for finance 16:332:503.
//  Created by Shounak Rangwala on 9/22/19.
//  Copyright © 2019 Shounak Rangwala. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<int> inputDimensions (){
    vector<int> matrixDimensions;
    int rows,columns;
    cout<<"enter the number of rows: "<<endl;
    cin>>rows;
    while(rows<=0 || rows>10){
        cout<<"out of bounds, enter dimension less than 10"<<endl;
        cin>>rows;
    }
    matrixDimensions.push_back(rows);
    cout<<"enter the number of columns: "<<endl;
    cin>>columns;
    while(columns<=0 || columns>10){
        cout<<"out of bounds, enter dimension less than 10"<<endl;
        cin>>columns;
    }
    matrixDimensions.push_back(columns);
    return matrixDimensions;
}

void inputValues(vector<int>&dimensions,vector<vector<double>> &Matrix){
    int rows = dimensions.front();
    int columns = dimensions.back();
    Matrix.resize(rows);
    for(int i=0;i<Matrix.size();i++){
        Matrix[i].resize(columns);
    }
    cout<< "enter the elements of your matrix"<<endl;
    for(int i=0;i<Matrix.size();i++){
        for(int j=0;j<Matrix[i].size();j++){
            cin>>Matrix[i][j];
        }
    }
//    for(int i=0;i<Matrix.size();i++){
//        for(int j=0;j<Matrix[i].size();j++){
////            cin>>input;
//            cout<<Matrix[i][j];
//        }
//        cout<<endl;
//    }
}

void DisplayMatrix(vector<vector<double>> &Matrix){
    for(int i=0;i<Matrix.size();i++){
        for(int j=0;j<Matrix[i].size();j++){
            cout<<setw(10)<<Matrix[i][j];
        }
        cout<<endl;
    }
}

void Addition (){
    cout<<"enter dimensions of First matrix"<<endl;
    vector<int> Mat1Dims = inputDimensions();
    cout<<"enter dimensions of second matrix"<<endl;
    vector<int> Mat2Dims = inputDimensions();
    
    if(Mat1Dims.front()!= Mat2Dims.front() || Mat1Dims.back()!= Mat2Dims.back()){
        cout<< "operation not supported"<<endl;
        return;
    }
    vector<vector<double>> Matrix1, Matrix2, result;
    inputValues(Mat1Dims, Matrix1);
    inputValues(Mat2Dims, Matrix2);
    result.resize(Mat1Dims.front());
    for(int i=0;i<result.size();i++){
        result[i].resize(Mat1Dims.back());
    }
    
    for(int i=0;i<Matrix1.size();i++){
        for(int j=0;j<Matrix1[i].size();j++){
            result[i][j] = Matrix2[i][j]+Matrix1[i][j];
        }
    }
    DisplayMatrix(result);
}

void Subtraction(){
    cout<<"enter dimensions of First matrix"<<endl;
    vector<int> Mat1Dims = inputDimensions();
    cout<<"enter dimensions of second matrix"<<endl;
    vector<int> Mat2Dims = inputDimensions();
    
    if(Mat1Dims.front()!= Mat2Dims.front() || Mat1Dims.back()!= Mat2Dims.back()){
        cout<< "operation not supported"<<endl;
        return;
    }
    vector<vector<double>> Matrix1, Matrix2, result;
    inputValues(Mat1Dims, Matrix1);
    inputValues(Mat2Dims, Matrix2);
    result.resize(Mat1Dims.front());
    for(int i=0;i<result.size();i++){
        result[i].resize(Mat1Dims.back());
    }
    
    for(int i=0;i<Matrix1.size();i++){
        for(int j=0;j<Matrix1[i].size();j++){
            result[i][j] = Matrix2[i][j]-Matrix1[i][j];
        }
    }
    DisplayMatrix(result);
}

void Multiplication(){
    cout<<"enter dimensions of First matrix"<<endl;
    vector<int> Mat1Dims = inputDimensions();
    cout<<"enter dimensions of second matrix"<<endl;
    vector<int> Mat2Dims = inputDimensions();
    
    if(Mat2Dims.front()!= Mat1Dims.back()){
        cout<< "operation not supported"<<endl;
        return;
    }
    vector<vector<double>> Matrix1, Matrix2, result;
    cout<<"enter values in 1st matrix"<<endl;
    inputValues(Mat1Dims, Matrix1);
    cout<<"enter values in 2nd matrix"<<endl;
    inputValues(Mat2Dims, Matrix2);
    
    result.resize(Mat1Dims.front());
    for(int i=0;i<result.size();i++){
        result[i].resize(Mat2Dims.back(),0);
    }
    
    
    for(int i=0;i<Mat1Dims.front();i++){
        for(int j=0;j<Mat2Dims.back();j++){
            for(int k=0; k<Mat1Dims.back();k++)
            result[i][j] += Matrix1[i][k]*Matrix2[k][j];
        }
    }
    DisplayMatrix(result);
}

void Transpose(){
    cout<<"enter dimensions of the matrix"<<endl;
    vector<int> Mat1Dims = inputDimensions();
    
    vector<vector<double>> Matrix1, result;
    cout<<"enter values in the matrix"<<endl;
    inputValues(Mat1Dims, Matrix1);
    
    result.resize(Mat1Dims.back());
    for(int i=0;i<result.size();i++){
        result[i].resize(Mat1Dims.front(),0);
    }
    
    
    for(int i=0;i<Mat1Dims.front();i++){
        for(int j=0;j<Mat1Dims.back();j++){
            result[j][i] = Matrix1[i][j];
        }
    }
    DisplayMatrix(result);
}

void Determinant(){
    
    cout<<"enter dimensions of the matrix"<<endl;
    vector<int> Mat1Dims = inputDimensions();
        
    if(Mat1Dims.front()!= 3 || Mat1Dims.back()!=3){
        cout<< "operation not supported"<<endl;
        return;
    }
    vector<vector<double>> Matrix1;
    double result;
    cout<<"enter values in the matrix"<<endl;
    inputValues(Mat1Dims, Matrix1);
    result=Matrix1[0][0]*(Matrix1[1][1] * Matrix1[2][2]-Matrix1[2][1]*Matrix1[1][2]) - Matrix1[0][1]*(Matrix1[1][0]*Matrix1[2][2] - Matrix1[2][0]*Matrix1[1][2]) + Matrix1[0][2]*(Matrix1[1][0]*Matrix1[2][1]-Matrix1[2][0]*Matrix1[1][1]);
    
    cout<<"the determinant is "<<result<<endl;
}

void Inverse(){
    cout<<"enter dimensions of the matrix"<<endl;
    vector<int> Mat1Dims = inputDimensions();
        
    if(Mat1Dims.front()!= 3 || Mat1Dims.back()!=3){
        cout<< "operation not supported"<<endl;
        return;
    }
    vector<vector<double>> Matrix1,transposeMatrix;
    double result;
    cout<<"enter values in the matrix"<<endl;
    inputValues(Mat1Dims, Matrix1);
    result=Matrix1[0][0]*(Matrix1[1][1] * Matrix1[2][2]-Matrix1[2][1]*Matrix1[1][2]) - Matrix1[0][1]*(Matrix1[1][0]*Matrix1[2][2] - Matrix1[2][0]*Matrix1[1][2]) + Matrix1[0][2]*(Matrix1[1][0]*Matrix1[2][1]-Matrix1[2][0]*Matrix1[1][1]);
    
    if(result ==0){
        cout<<" operation not possible"<<endl;
        return;
    }
    
    transposeMatrix.resize(Mat1Dims.back());
    for(int i=0;i<transposeMatrix.size();i++){
        transposeMatrix[i].resize(Mat1Dims.front(),0);
    }
    
    
    for(int i=0;i<Mat1Dims.front();i++){
        for(int j=0;j<Mat1Dims.back();j++){
            transposeMatrix[j][i] = Matrix1[i][j];
        }
    }
    
    //Calculate 2-complement of matrix.
    vector<vector<double>> complementMatrix;
    complementMatrix.resize(Mat1Dims.back());
    for(int i=0;i<complementMatrix.size();i++){
        complementMatrix[i].resize(Mat1Dims.front(),0);
    }
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
    vector<vector<double>> preInverseMatrix;
    preInverseMatrix.resize(Mat1Dims.back());
    for(int i=0;i<preInverseMatrix.size();i++){
        preInverseMatrix[i].resize(Mat1Dims.front(),0);
    }
    
    for (int i = 0; i < Mat1Dims.front(); i++) {
        for (int j = 0; j < Mat1Dims.back(); j++) {
            preInverseMatrix[i][j] = complementMatrix[i][j] / result;
        }
    }
    
    //The result is transpose of pre-result.
    vector<vector<double>> InverseMatrix;
    InverseMatrix.resize(Mat1Dims.back());
    for(int i=0;i<InverseMatrix.size();i++){
        InverseMatrix[i].resize(Mat1Dims.front(),0);
    }
    
    for (int i = 0; i < Mat1Dims.front(); i++) {
        for (int j = 0; j < Mat1Dims.back(); j++) {
            InverseMatrix[j][i] = preInverseMatrix[i][j];
        }
    }
    cout<<" The ans is: "<<endl;
    DisplayMatrix(InverseMatrix);
    return;
}

int main(){
//    vector<int> dims =inputDimensions();
//    vector<vector<int>>matrix1;
//    inputValues(dims,matrix1);
    
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
